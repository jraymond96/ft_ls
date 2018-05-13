/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_startchoose.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 02:37:23 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/10 05:50:56 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_btree	*ft_found_place(t_btree *elem, t_choose *inf, int *i,
							int (comp)(void *, void *))
{
	while (elem)
	{
		inf->parent = elem;
		*i = comp(inf->ptr, elem->ptrdata);
		elem = (*i < 0) ? (t_btree *)elem->left : (t_btree *)elem->right;
	}
	elem = inf->parent;
	return (elem);
}

void	ft_left(t_btree *elem, t_choose *inf, int *i)
{
	void	*ptrfonc[2];
	int		x;

	ptrfonc[0] = inser_lascii;
	ptrfonc[1] = inser_ltime;
	inf->parent = elem;
	x = 0;
	if (!elem->left)
		elem->left = (struct s_btree *)ft_newbtree(inf->ptr, sizeof(t_linfo));
	else
	{
		elem = elem->left;
		if (inf->flags & MIN_T)
			x = 1;
		elem = ft_found_place(elem, inf, i, ptrfonc[x]);
	}
	if (*i < 0)
		elem->left = (t_btree *)ft_newbtree(inf->ptr, sizeof(t_linfo));
	else
		elem->right = (t_btree *)ft_newbtree(inf->ptr, sizeof(t_linfo));
	elem->parent = (struct s_btree *)inf->parent;
}

void	ft_right(t_btree *elem, t_choose *inf, int *i)
{
	void	*ptrfonc[2];
	int		x;

	ptrfonc[0] = inser_lascii;
	ptrfonc[1] = inser_ltime;
	inf->parent = elem;
	x = 0;
	if (!elem->right)
		elem->right = (struct s_btree *)ft_newbtree(inf->ptr, sizeof(t_linfo));
	else
	{
		elem = elem->right;
		if (inf->flags & MIN_T)
			x = 1;
		elem = ft_found_place(elem, inf, i, ptrfonc[x]);
	}
	if (*i < 0)
		elem->left = (t_btree *)ft_newbtree(inf->ptr, sizeof(t_linfo));
	else
		elem->right = (t_btree *)ft_newbtree(inf->ptr, sizeof(t_linfo));
	elem->parent = (struct s_btree *)inf->parent;
}

t_btree	*ft_btree_start(t_btree *root, t_choose *data, char *path, int branch)
{
	t_btree		*elem;
	int			i;
	t_linfo		info;

	i = 0;
	info.name = ft_strdup(path);
	info.time = data->stats->st_mtime;
	data->ptr = &info;
	if (!root)
	{
		elem = ft_newbtree(NULL, 0);
		root = elem;
	}
	else
		elem = root;
	if (branch == 0)
		ft_left(elem, data, &i);
	else
		ft_right(elem, data, &i);
	return (root);
}
