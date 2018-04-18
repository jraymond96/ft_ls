/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_btree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:23:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/18 07:47:16 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"

void	ft_print_treel(t_btree *root, t_lenmax *max)
{
	t_btree	*elem;
	int		padd;

	elem = root;
	if (elem->left)
		ft_print_tree((t_btree *)elem->left, max);
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
	{
		padd = ft_ilen(((t_finfo *)root->ptrdata)->n_link);
		padd = max->lenmax_link - padd + 12;
		printf("%-*s%d ", padd, ((t_finfo *)root->ptrdata)->mode, ((t_finfo *)root->ptrdata)->n_link);
		printf("%-*s", (max->lenmax_u + 2), ((t_finfo *)root->ptrdata)->n_id_user);
		printf("%-*s", (max->lenmax_g + 2), ((t_finfo *)root->ptrdata)->n_id_group);
		printf("%*d ", max->lenmax_oct, ((t_finfo *)root->ptrdata)->size);
		printf("%s ", ((t_finfo *)root->ptrdata)->timeday);
		if (((t_finfo *)root->ptrdata)->link)
		{
			printf("%s", ((t_finfo *)root->ptrdata)->name);
			printf(" -> %s\n", ((t_finfo *)root->ptrdata)->link);
		}
		else
			printf("%s\n", ((t_finfo *)root->ptrdata)->name);
	}
	if (elem->right)
		ft_print_tree((t_btree *)elem->right, max);
}

void	ft_print_treerl(t_btree *root, t_lenmax *max)
{
	t_btree	*elem;
	int		padd;

	elem = root;
	if (elem->right)
		ft_print_tree((t_btree *)elem->right, max);
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
	{
		padd = ft_ilen(((t_finfo *)root->ptrdata)->n_link);
		padd = max->lenmax_link - padd + 12;
		printf("%-*s%d ", padd, ((t_finfo *)root->ptrdata)->mode, ((t_finfo *)root->ptrdata)->n_link);
		printf("%-*s", (max->lenmax_u + 2), ((t_finfo *)root->ptrdata)->n_id_user);
		printf("%-*s", (max->lenmax_g + 2), ((t_finfo *)root->ptrdata)->n_id_group);
		printf("%*d ", max->lenmax_oct, ((t_finfo *)root->ptrdata)->size);
		printf("%s ", ((t_finfo *)root->ptrdata)->timeday);
		if (((t_finfo *)root->ptrdata)->link)
		{
			printf("%s", ((t_finfo *)root->ptrdata)->name);
			printf(" -> %s\n", ((t_finfo *)root->ptrdata)->link);
		}
		else
			printf("%s\n", ((t_finfo *)root->ptrdata)->name);
	}
	if (elem->left)
		ft_print_tree((t_btree *)elem->left, max);
}

void	ft_print_treen(t_btree *root, t_lenmax *max)
{
	t_btree	*elem;

	elem = root;
	if (elem->left)
		ft_print_tree((t_btree *)elem->left, max);
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
		ft_putendl(((t_finfo *)root->ptrdata)->name);
	if (elem->right)
		ft_print_tree((t_btree *)elem->right, max);
}

void	ft_print_treern(t_btree *root, t_lenmax *max)
{
	t_btree	*elem;

	elem = root;
	if (elem->right)
		ft_print_tree((t_btree *)elem->right, max);
	if (max->flags & MIN_A || ((t_finfo *)elem->ptrdata)->name[0] != '.')
		ft_putendl(((t_finfo *)root->ptrdata)->name);
	if (elem->left)
		ft_print_tree((t_btree *)elem->left, max);
}

void	ft_print_tree(t_btree *root, t_lenmax *max)
{
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
