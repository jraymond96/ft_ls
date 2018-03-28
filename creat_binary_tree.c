/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_binary_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:25:23 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/28 09:39:13 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"

t_btree	*ft_creat_belem(void)
{
	t_btree	*new;
	size_t	size;

	if (!(new = (t_btree *)malloc((size = sizeof(t_btree)))))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}

t_btree *ft_newbtree(void const *data, size_t size_data)
{
	t_btree	*new;

	if (!(new = ft_creat_belem()))
		return (NULL);
	if (!data || !size_data)
	{
		new->ptrdata = NULL;
		new->data_size = 0;
	}
	else
	{
		if (!(new->ptrdata = (void *)malloc(size_data)))
		{
			ft_memdel((void **)&new);
			return (NULL);
		}
		ft_memmove(new->ptrdata, data, size_data);
		new->data_size = size_data;
	}
	return (new);
}

/*
**int		ft_compdata(void *data , void *data2, size_t data_size)
**{
**	int	res;
**
**	res = ft_strcmp(data, data2);
**	(void)data_size;
**	return (res);
**}
*/

t_btree	*ft_btreeinser_ascii(t_btree *root, void *data, size_t size_data)
{
	t_btree	*elem;
	t_btree	*parent;
	int	res;

	if (!(elem = root))
		return (ft_newbtree(data, size_data));
	parent = root;
	while (elem)
	{
		res = ft_strcmp(((t_test *)data)->name, ((t_test *)elem->ptrdata)->name);
		elem = (res < 0) ? (t_btree *)elem->left : (t_btree *)elem->right;
		if (!elem)
		{
			elem = parent;
			break;
		}
		parent = elem;
	}
	if (res < 0)
		elem->left = (struct s_btree *)ft_newbtree(data, size_data);
	else
		elem->right = (struct s_btree *)ft_newbtree(data, size_data);
	elem->parent = (struct s_btree *)parent;
	return (root);
}
