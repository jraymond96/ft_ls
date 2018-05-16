/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:49:29 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/16 15:06:13 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

void	ft_atime(struct stat *allstats, t_finfo *file_st)
{
	char	*file_time;
	time_t	curr_time;

	file_time = ctime((const time_t *)&allstats->st_atime);
	file_st->time_n = allstats->st_atime;
	time(&curr_time);
	ft_strncat(file_st->timeday, (file_time + 4), 12);
	if (ft_strlen(file_st->timeday) != 12)
		ft_memmove(&file_st->timeday[4], &file_st->timeday[3], 9);
	if (((int)curr_time - (int)allstats->st_atime) > 15624439 ||
			((int)curr_time - (int)allstats->st_atime) < 0)
		ft_memmove(&file_st->timeday[7], &file_time[19], 5);
}

void	ft_ctime(struct stat *allstats, t_finfo *file_st)
{
	char	*file_time;
	time_t	curr_time;

	file_time = ctime((const time_t *)&allstats->st_ctime);
	file_st->time_n = allstats->st_ctime;
	time(&curr_time);
	ft_strncat(file_st->timeday, (file_time + 4), 12);
	if (ft_strlen(file_st->timeday) != 12)
		ft_memmove(&file_st->timeday[4], &file_st->timeday[3], 9);
	if (((int)curr_time - (int)allstats->st_ctime) > 15624439 ||
			((int)curr_time - (int)allstats->st_ctime) < 0)
		ft_memmove(&file_st->timeday[7], &file_time[19], 5);
}

void	ft_file_time(struct stat *allstats, t_finfo *file_st, int flags)
{
	char	*file_time;
	time_t	curr_time;

	if ((flags & MIN_U || flags & MAX_U) && !(flags & MIN_T))
	{
		if (flags & MIN_U)
			ft_atime(allstats, file_st);
		else
			ft_ctime(allstats, file_st);
		return ;
	}
	file_time = ctime((const time_t *)&allstats->st_mtime);
	file_st->time_n = allstats->st_mtime;
	time(&curr_time);
	ft_strncat(file_st->timeday, (file_time + 4), 12);
	if (ft_strlen(file_st->timeday) != 12)
		ft_memmove(&file_st->timeday[4], &file_st->timeday[3], 9);
	if (((int)curr_time - (int)allstats->st_mtime) > 15624439 ||
			((int)curr_time - (int)allstats->st_mtime) < 0)
		ft_memmove(&file_st->timeday[7], &file_time[19], 5);
}
