/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 04:49:42 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/03 18:16:31 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>

int		ft_error(char *path, int flags, int nb_arg)
{
	if (flags & MAX_R || nb_arg != 1)
	{
		ft_printf("%s:\n", path);
		ft_dprintf(2, "ls: %s: %s\n", tname_file(path),
						strerror(errno));
	}
	else
		ft_dprintf(2, "ls: %s: %s\n", tname_file(path),
						strerror(errno));
	return (0);
}
