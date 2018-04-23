/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:02:11 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/23 15:29:05 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_call_stat(struct stat *allstats, int flags, char *path)
{
	char	*str;

	(void)flags;
	if ((lstat(path, allstats) == -1))
	{
		str = ft_strjoin("ls: ", path);
		perror(str);
	}
	else
		return (0);
	ft_memdel((void **)&str);
	return (-1);
}
