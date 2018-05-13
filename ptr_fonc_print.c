/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_fonc_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:34:00 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/13 07:48:52 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static t_mask	g_mask[] = {
	{'R', MAX_R}, {'a', MIN_A}, {'l', MIN_L}, {'r', MIN_R},
	{'t', MIN_T}
};

/*void	long_print(t_btree *elem, t_lenmax *max)
{
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
	{
		if (PATH->size != -1)
		{
			ft_printf("%s  %*d %-*s  %-*s   %*d %s %s", \
			PATH->mode, max->lenmax_link, PATH->n_link, max->lenmax_u, \
			PATH->n_id_user, max->lenmax_g, PATH->n_id_group, max->lenmax_oct, \
			PATH->size, PATH->timeday, PATH->name);
		}
		else
		{
			ft_printf("%s  %*d %-*s  %-*s   %*d, %*d %s %s", \
			PATH->mode, max->lenmax_link, PATH->n_link, max->lenmax_u, \
			PATH->n_id_user, max->lenmax_g, PATH->n_id_group, \
			max->lenmax_majo, PATH->major, max->lenmax_mino, PATH->minor, \
			PATH->timeday, PATH->name);
		}
		if (((t_finfo *)elem->ptrdata)->link)
			ft_printf(" -> %s\n", PATH->link);
		else
			ft_putchar('\n');
	}
}

void	normal_print(t_btree *elem, t_lenmax *max, int len)
{
	(void)len;
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
		ft_putendl(PATH->name);
}
*/
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
			printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n",
						arg[x]);
			return (-1);
		}
	}
	return (flags);
}
