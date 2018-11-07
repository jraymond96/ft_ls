/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 23:31:20 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/16 14:16:32 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** - bin : look if on str all are flags and return int with inside boolean,
** 	activated if flags are or not, and if on flags are not good bin can print
**	somethings (bin)(argv, 0, -1, 0) (bin)(argv, x, y, flags);
** - get_opt return : 0 if no entry after flags, or numb > 0 who are the
**  indice of first entry on argv after flags, or -1 if flags no admitted;
*/

#include "libft.h"
#include <stdio.h>

int		is_opt(char *argv)
{
	if (!argv)
		return (-1);
	if (argv[0] == '-')
	{
		if (argv[1] == '-' && ft_strlen(argv) == 2)
			return (2);
		else
			return (1);
	}
	else
		return (0);
}

int		bin_opt(char *argv, int flags, int (bin)(char *, int, int, int))
{
	int	fl;

	if ((fl = bin(argv, 0, -1, 0)) < 0)
		return (-1);
	fl |= flags;
	return (fl);
}

int		ft_get_opt(char **argv, int *flags, int (bin)(char *, int, int, int))
{
	int		x;
	int		ret;

	x = 1;
	*flags = 0;
	while ((ret = is_opt(argv[x])) == 1)
	{
		if ((*flags = bin_opt(argv[x++], *flags, bin)) < 0)
			return (-1);
	}
	if (ret == 0)
		return (x);
	else if (ret == 2)
	{
		if (argv[++x])
			return (x);
		else
			return (0);
	}
	if (ret == -1)
		return (0);
	return (ret);
}
