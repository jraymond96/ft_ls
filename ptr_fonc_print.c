/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_fonc_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:34:00 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/15 07:29:40 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_mask	g_mask[] = {
	{'R', MAX_R}, {'a', MIN_A}, {'l', MIN_L}, {'r', MIN_R},
	{'t', MIN_T}
};

int		astobin(char *arg, int x, int y, int flags)
{
	char	*ptr;

	while (arg[++x])
	{
		if ((ptr = ft_strchr("Ralrt", arg[x])))
		{
			y = -1;
			while (++y < 5)
			{
				if (g_mask[y].flags == *ptr)
				{
					flags |= g_mask[y].mask;
					break ;
				}
			}
		}
		else
		{
			ft_printf("ls: illegal option -- %c\nusage: ls [-%s] [file ...]\n",
						arg[x], "Ralrt");
			return (-1);
		}
	}
	return (flags);
}
