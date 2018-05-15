/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 04:49:42 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/15 06:47:18 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>

int		ft_error(char *path, int nb_arg)
{
	if (nb_arg > 1)
		ft_dprintf(2, "%s:\nls: %s: %s\n", path, tname_file(path),
						strerror(errno));
	else
		ft_dprintf(2, "ls: %s: %s\n", tname_file(path),
						strerror(errno));
	return (0);
}
