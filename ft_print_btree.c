/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_btree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:23:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/03 15:58:17 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"

void	ft_print_tree(t_btree *root)
{
	t_btree	*elem;

	elem = root;
	if (elem->left)
		ft_print_tree((t_btree *)elem->left);
	if (((t_finfo *)elem->ptrdata)->name[0] != '.')
	{
		ft_putstr(((t_finfo *)elem->ptrdata)->name);
		ft_putchar('\n');
	}
	if (elem->right)
		ft_print_tree((t_btree *)elem->right);
}
