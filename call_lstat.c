/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_lstat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 04:27:09 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/12 04:27:11 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		call_lstat(struct stat *allstats, char *path)
{
	if ((lstat(path, allstats) == -1))
		ft_printf("ls: %s: %s\n", path, strerror(errno));
	else
		return (0);
	return (-1);
}
