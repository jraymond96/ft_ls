/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_btdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:44:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 23:57:18 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"

void	del(void *elem, size_t content_size)
{
	(void)content_size;
	ft_memdel((void **)&elem);
}

void	btdelbis(void *elem)
{
	ft_memdel(&elem);
}

void	btdel(void *elem)
{
	ft_memdel((void **)&((t_finfo *)elem)->name);
	ft_memdel((void **)&((t_finfo *)elem)->link);
	ft_memdel((void **)&((t_finfo *)elem)->n_id_user);
	ft_memdel((void **)&((t_finfo *)elem)->n_id_group);
	ft_memdel(&elem);
}

void	ft_free_all(t_list **list, t_btree **root, DIR *dir, char **path)
{
	void	*ptr_tl;
	void	*ptr_tbt;

	ptr_tl = del;
	ptr_tbt = btdel;
	ft_lstdel(list, ptr_tl);
	ft_btreedel(root, ptr_tbt);
	ft_memdel((void **)path);
	closedir(dir);
}
