/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takeopt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:23:23 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/05 12:51:31 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_erroropt(int i, char const **argv)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(argv[i / 10][i % 10]);
	ft_putendl("\nusage: ls [-Ralrt] [file ...]");
	return (0);
}

int		ft_takeopt(char const **argv, const char *optstring, char **opt)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (argv[++i])
	{
		if (argv[i][y++] != '-')
			return (-i);
		while (argv[i][y++])
		{
			if (!(ft_strchr(optstring, argv[i][y])))
				return ((i * 10) + y);
		}
		if (!*opt)
			*opt = ft_strdup(&argv[i][1]);
		else
			*opt = ft_strjoin_free(*opt, &argv[i][1], 1);
		y = 0;
	}
	return (0);
}
