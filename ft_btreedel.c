/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:05:32 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/30 16:18:49 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_btreedel(t_btree **root, void (*btdel)(void *))
{
	ft_putendl("nb de rappel :");
	if (!root || !btdel)
		return ;
	if ((*root)->left)
		ft_btreedel((t_btree **)&((*root)->left), btdel);
	if ((*root)->right)
		ft_btreedel((t_btree **)&((*root)->right), btdel);
	btdel((*root)->ptrdata);
	ft_memdel((void **)(*root)->ptrdata);
	if (root)
	{
		(*root)->parent = NULL;
		(*root)->left = NULL;
		(*root)->right = NULL;
		ft_memdel((void **)root);
	}
}
