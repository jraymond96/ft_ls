/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_fonc_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:34:00 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/10 00:01:15 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	long_print(t_btree *elem, t_lenmax *max)
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
/*	int	res;

	*/(void)len;/*
	res = max->nb_col / max->lenmax_name + 2;
	res = len / res;
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
		ft_printf("%-*s\n", res, PATH->name);*/
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
		ft_putendl(PATH->name);
}

int		lst_cmp(t_list *elem)
{
	return (ft_strcmp(((t_finfo *)elem->content)->name,
				((t_finfo *)elem->next->content)->name));
}
