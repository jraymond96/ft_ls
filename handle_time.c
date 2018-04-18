/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:49:29 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/18 08:02:42 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "lib/libft.h"

void	ft_file_time(struct stat *allstats, t_finfo *file_st)
{
	char 	*file_time;
	time_t	curr_time;

	time(&curr_time);
	file_st->time_n = allstats->st_mtime;
	file_time = ctime((const time_t *)&allstats->st_mtime);
	ft_strncat(file_st->timeday, (file_time + 4), 12);
	if (ft_strlen(file_st->timeday) != 12)
		ft_memmove(&file_st->timeday[4], &file_st->timeday[3], 9);
	if (((int)curr_time - (int)allstats->st_mtime) > 15624439)
		ft_memmove(&file_st->timeday[7], &file_time[19], 5);
}
