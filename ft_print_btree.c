/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_btree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:23:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 07:33:58 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"
#include "./ft_printf/ft_printf.h"

void	print_tree(t_btree *root, t_lenmax *max, void (print)(t_btree *,
						t_lenmax *, int), int len)
{
	t_btree	*elem;

	elem = root;
	if (elem->left)
		print_tree((t_btree *)elem->left, max, print, len);
	print(elem, max, len);
	if (elem->right)
		print_tree((t_btree *)elem->right, max, print, len);
}

void	print_revtree(t_btree *root, t_lenmax *max, void (print)(t_btree *,
							t_lenmax *, int), int len)
{
	t_btree	*elem;

	elem = root;
	if (elem->right)
		print_revtree((t_btree *)elem->right, max, print, len);
	print(elem, max, len);
	if (elem->left)
		print_revtree((t_btree *)elem->left, max, print, len);
}

void	print_related_flags(t_btree *root, t_lenmax *max, void **ptr_fonc)
{
	int	x;
	int	len;

	x = 0;
	len = ft_how_dir(root, -1);
	if (!(max->flags & MIN_L))
		x = 1;
	if (max->flags & MIN_R)
		print_revtree(root, max, ptr_fonc[x], ft_how_dir(root, 0));
	else
		print_tree(root, max, ptr_fonc[x], ft_how_dir(root, 0));
}

void	ft_print_tree(t_btree *root, t_lenmax *max, t_recur *rec)
{
	int		res;
	void	*ptr[3];

	ptr[0] = long_print;
	ptr[1] = normal_print;
	ptr[2] = NULL;
	if (rec->nb_arg > 1)
		ft_printf("%s:\n", max->path);
	else
	{
		if (max->flags & MAX_R && rec->a & (1 << 0))
			ft_printf("%s:\n", max->path);
	}
	if (max->flags & MAX_R)
		rec->a |= (1 << 0);
	res = is_empty(root, 0);
	if (max->flags & MIN_L && (max->total_size || max->flags & MIN_A || res))
		ft_printf("total %lld\n", max->total_size);
	print_related_flags(root, max, &ptr[0]);
}
