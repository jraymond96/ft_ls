/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_binary_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:25:23 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/19 21:36:38 by jraymond         ###   ########.fr       */
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
	t_btree->parent = NULL;
	t_btree->left = NULL;
	t_btree->right = NULL;
	return (new);
}

t_btree	*ft_insertion_ascii(t_btree *root, void *data)
{
	t_btree	*elem;

	elem = root;
	while (elem)
	{
		if ((res = ft_strcmp(((char *)data)->name,
				((char *)elem->ptrdata)->name)) < 0)
			elem->left ? elem = elem->left : break;
		else
			elem->right ? elem = elem->right : break;
	}
	if (res < 0)
		elem->left = ft_newbtree(elem->data_size);
	else
		elem->right = ft_newbtree(elem->data_size);
}

t_btree *ft_newbtree(void const *data, size_t size_data)
{
	t_btree	*new;

	if (!(new = ft_new)
	if (!data)
	{
		new->ptrdata = NULL;
		new->data_size = 0;
	}
	else
	{
		if (!(new->ptrdata = (void *)malloc(size_data)))
		{
			ft_memdel(&new);
			return (NULL);
		}
		ft_memmove(new->ptrdata, data, size_data);
		new->data->size = size_data;
	}
	return (new)
}
