/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strofpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 05:11:39 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/25 13:57:20 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_how_arg(char **argv)
{
	int	x;
	int	res;

	x = 1;
	res = 0;
	while (argv[x] && argv[x][0] == '-')
		x++;
	while (argv[x++])
		res++;
	return (res);
}

int		ft_strofpoint(char *str)
{
	while (*str)
	{
		if (*str != '.')
			return (-1);
		str++;
	}
	return (0);
}
