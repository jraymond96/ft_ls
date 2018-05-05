/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_btree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:23:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/05 19:06:42 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"
#include "./ft_printf/ft_printf.h"

void	ft_print_treel(t_btree *root, t_lenmax *max)
{
	t_btree	*elem;

	elem = root;
	if (elem->left)
		ft_print_treel((t_btree *)elem->left, max);
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
		if (((t_finfo *)root->ptrdata)->link)
			ft_printf(" -> %s\n", ((t_finfo *)root->ptrdata)->link);
		else
			ft_putchar('\n');
	}
	if (elem->right)
		ft_print_treel((t_btree *)elem->right, max);
}

void	ft_print_treerl(t_btree *root, t_lenmax *max)
{
	t_btree	*elem;

	elem = root;
	if (elem->right)
		ft_print_treerl((t_btree *)elem->right, max);
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
		if (((t_finfo *)root->ptrdata)->link)
			ft_printf(" -> %s\n", ((t_finfo *)root->ptrdata)->link);
		else
			ft_putchar('\n');
	}
	if (elem->left)
		ft_print_treerl((t_btree *)elem->left, max);
}

void	ft_print_treen(t_btree *root, t_lenmax *max)
{
	t_btree	*elem;

	elem = root;
	if (elem->left)
		ft_print_treen((t_btree *)elem->left, max);
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
		ft_putendl(((t_finfo *)root->ptrdata)->name);
	if (elem->right)
		ft_print_treen((t_btree *)elem->right, max);
}

void	ft_print_treern(t_btree *root, t_lenmax *max)
{
	t_btree	*elem;

	elem = root;
	if (elem->right)
		ft_print_treern((t_btree *)elem->right, max);
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
		ft_putendl(((t_finfo *)root->ptrdata)->name);
	if (elem->left)
		ft_print_treern((t_btree *)elem->left, max);
}

void	ft_print_tree(t_btree *root, t_lenmax *max, int nb_arg)
{
	int	res;

	if (nb_arg > 1 || (MAX_R & max->flags && ft_strlen(max->path) > 1))
		ft_printf("%s:\n", max->path);
	res = is_empty(root, 0);
	if (max->flags & MIN_L && (max->total_size || max->flags & MIN_A || res))
		printf("total %lld\n", max->total_size);
	if (MIN_L & max->flags)
	{
		if (MIN_R & max->flags)
			ft_print_treerl(root, max);
		else
			ft_print_treel(root, max);
	}
	else
	{
		if (MIN_R & max->flags)
			ft_print_treern(root, max);
		else
			ft_print_treen(root, max);
	}
}
