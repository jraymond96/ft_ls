/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:02:11 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 22:06:34 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_call_stat(struct stat *allstats, int flags, char *path)
{
	(void)flags;
	if ((lstat(path, allstats) == -1))
		ft_printf("ls: %s: %s\n", path, strerror(errno));
	else
		return (0);
	return (-1);
}
