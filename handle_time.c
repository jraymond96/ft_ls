/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:28:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/17 23:11:11 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "lib/libft.h"

void	ft_file_time(struct stat *allstats, t_finfo *file_st)
{
	char *time;

	time = ctime((const time_t *)&allstats->st_mtime);
	printf("real time : %s\n", time);
	ft_strncat(file_st->timeday, (time + 4), 12);
	printf("TIME : %s\n", file_st->timeday);
	if (ft_strlen(file_st->timeday) != 12)
		ft_memmove(&file_st->timeday[4], &file_st->timeday[3], 9);
}
