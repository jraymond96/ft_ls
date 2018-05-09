/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 01:09:43 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 06:40:35 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_applymask(int *i, char flags)
{
	if (flags == 'R')
		*i |= MAX_R;
	else if (flags == 'a')
		*i |= MIN_A;
	else if (flags == 'l')
		*i |= MIN_L;
	else if (flags == 'r')
		*i |= MIN_R;
	else
		*i |= MIN_T;
}

int		ft_binaryflags(char *flags)
{
	int	i;

	i = 0;
	while (*flags)
	{
		if (ft_strchr("Ralrt", *flags))
			ft_applymask(&i, *flags);
		flags++;
	}
	return (i);
}

int		ft_takeopt(char const **argv, const char *optstring, char **opt)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (argv[++i] && (argv[i][y++] == '-' && argv[i][y] != '-'))
	{
		while (argv[i][y])
		{
			if (!(ft_strchr(optstring, argv[i][y])))
			{
				return ((i * 10) + y);
			}
			y++;
		}
		if (!*opt)
			*opt = ft_strdup(&argv[i][1]);
		else
			*opt = ft_strjoin_free(*opt, &argv[i][1], 1);
		y = 0;
	}
	return (0);
}

int		ft_option_management(char const **arg, char **flags)
{
	int	i;

	i = 0;
	if (!arg[1])
		return (0);
	if ((i = ft_takeopt((const char **)arg, "Ralrt", flags)) > 0)
	{
		if (flags)
			ft_memdel((void **)flags);
		ft_printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n", \
				arg[i / 10][i % 10]);
		return (-1);
	}
	if (i != 0)
		return (0);
	if (*flags && i == 0)
	{
		i = 0;
		i = ft_binaryflags(*flags);
		ft_memdel((void **)flags);
	}
	return (i);
}
