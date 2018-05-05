/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insertree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:07:44 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/05 20:27:16 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	inser_ascii(void *data1, void *data2)
{
	return (ft_strcmp(((t_finfo *)data1)->name, ((t_finfo *)data2)->name));
}

int	inser_time(void *data1, void *data2)
{
	return (((t_finfo *)data1)->time_n - ((t_finfo *)data2)->time_n);
}

t_btree	*select_inser(t_btree *root, t_finfo *info, t_lenmax *max)
{
	void	*ptrfonc[3];

	(void)max;
	ptrfonc[0] = inser_ascii;
	ptrfonc[1] = inser_time;
	ptrfonc[2] = NULL;

	return (ft_btreeinser(root, info, sizeof(t_finfo), ptrfonc[0]));
}
