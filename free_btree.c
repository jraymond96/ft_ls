/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_btree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:21:21 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/30 16:23:50 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "ft_ls.h"

void	btdel(t_finfo *elem)
{
	ft_memdel((void **)&elem->name);
	ft_memdel((void **)&elem->n_id_user);
	ft_memdel((void **)&elem->n_id_group);
}

int	main(int argc, char **argv)
{
	t_list	*b_list;
	t_btree	*root;
	void	*ptrfonc;
	DIR		*dir;

	ptrfonc = &(btdel);
	if (argc != 2)
		return (0);
	if (!(dir = opendir(argv[1])))
	{
		ft_putstr("dir = NULL\n");
		return (0);
	}
	root = ft_take_files_infos(argv[1], dir, &b_list);
	ft_print_tree(root);
	ft_btreedel(&root, ptrfonc);
	return (0);
}
