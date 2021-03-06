/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insertree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:07:44 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/16 18:37:36 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		inser_ascii(void *data1, void *data2)
{
	return (ft_strcmp(((t_finfo *)data1)->name, ((t_finfo *)data2)->name));
}

int		inser_time(void *data1, void *data2)
{
	int	res;

	if ((res = ((t_finfo *)data2)->time_n - ((t_finfo *)data1)->time_n) == 0)
		return (inser_ascii(data1, data2));
	else
		return (res);
}

int		inser_size(void *data1, void *data2)
{
	int	res;

	if ((res = ((t_finfo *)data2)->size - ((t_finfo *)data1)->size) == 0)
		return (inser_ascii(data1, data2));
	else
		return (res);
}

t_btree	*select_inser(t_btree *root, t_finfo *info, t_lenmax *max)
{
	void	*ptrfonc[3];
	int		x;

	ptrfonc[0] = inser_ascii;
	ptrfonc[1] = inser_time;
	ptrfonc[2] = inser_size;
	x = 0;
	if (max->flags & MIN_T && !(max->flags & MAX_S))
		x = 1;
	if (max->flags & MAX_S)
		x = 2;
	return (ft_btreeinser(root, info, sizeof(t_finfo), ptrfonc[x]));
}
