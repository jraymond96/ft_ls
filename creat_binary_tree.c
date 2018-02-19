/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_binary_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:25:23 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/19 19:58:02 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.a"
#include "ft_ls.h"

t_btree	*ft_newbtree(size_t content_size)
{
	t_btree	*new;
	size_t	size;

	new = (t_btree *)malloc((size = sizeof(t_btree)))
	ft_bzero(new, size);
	t_btree->ptrdata = malloc(content_size);
	t_btree->left = NULL;
	t_btree->right = NULL;
	return (new);
}

t_btree	*ft_insertion_ascii(t_btree *root, void *data)

void	add_elem(t_btree **root, void *data)
{
	t_btree	*new_elem;

	new_elem = ft_newbtree(data);
	if (!(*root))
		*root = new_elem;
	else
	{
		while ()
	}
	return (root)
}
