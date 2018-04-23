/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strofpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 05:11:39 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/23 16:16:10 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_how_arg(char **argv)
{
	int	x;

	x = 0;
	while (argv[x][0] == '-' && argv[x])
		x++;
	if (argv[++x])
		return (1);
	else
		return (0);
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
