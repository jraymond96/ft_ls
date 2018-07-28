/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_lstat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 04:27:09 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/03 17:59:48 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>

int		call_lstat(struct stat *allstats, char *path)
{
	if (lstat(path, allstats) == -1 || (!(allstats->st_mode & S_IXUSR) &&
				(S_ISDIR(allstats->st_mode))))
	{
		if (!(DT_DIR & allstats->st_mode))
			ft_printf("ls: %s: %s\n", path, strerror(errno));
		return (-1);
	}
	else
		return (0);
}

int		call_llstat(struct stat *allstats, char *path)
{
	if (lstat(path, allstats) == -1)
	{
		ft_printf("ls: %s: %s\n", path, strerror(errno));
		return (-1);
	}
	else if (S_ISDIR(allstats->st_mode) && !(allstats->st_mode & S_IXUSR))
		return (2);
	else
		return (0);
}
