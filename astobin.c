/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_fonc_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:34:00 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/16 16:23:11 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_mask	g_mask[] = {
	{'R', MAX_R}, {'a', MIN_A}, {'l', MIN_L}, {'r', MIN_R},
	{'t', MIN_T}, {'u', MIN_U}, {'U', MAX_U}, {'S', MAX_S}
};

void		priority(int *flags, int y)
{
	if (y > 4)
	{
		if (y == 5)
			*flags &= ~(1 << 6);
		else
			*flags &= ~(1 << 5);
	}
}

int		astobin(char *arg, int x, int y, int flags)
{
	char	*ptr;

	while (arg[++x])
	{
		if ((ptr = ft_strchr("RSUalrtu", arg[x])))
		{
			y = -1;
			while (++y < 8)
			{
				if (g_mask[y].flags == *ptr)
				{
					flags |= g_mask[y].mask;
					priority(&flags, y);
					break ;
				}
			}
		}
		else
		{
			ft_printf("ls: illegal option -- %c\nusage: ls [-%s] [file ...]\n",
						arg[x], "RSUalrtu");
			return (-1);
		}
	}
	return (flags);
}
