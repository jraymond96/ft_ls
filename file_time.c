/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:28:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/17 22:41:02 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_file_time(struct stat *allstats, t_finfo *file_st)
{
	char *time;

	time = ctime((const time_t *)&allstats->st_mtime);
	ft_strncpy(file_st->timeday, (time + 4), 12);
}
