/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_btdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:44:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/16 19:26:28 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (elem)
	{
		if (PATH->name)
			ft_memdel((void **)&((t_finfo *)elem)->name);
		if (PATH->link)
			ft_memdel((void **)&((t_finfo *)elem)->link);
		if (PATH->n_id_user)
			ft_memdel((void **)&((t_finfo *)elem)->n_id_user);
		if (PATH->n_id_group)
			ft_memdel((void **)&((t_finfo *)elem)->n_id_group);
		ft_memdel(&elem);
	}
}

void	ft_free_all(t_btree **root, t_btree **folder, DIR *dir, t_lenmax *max)
{
	if (*root)
		ft_btreedel(root, btdel);
	if (*folder)
		ft_btreedel(folder, btdelbis);
	if (max->path)
		ft_memdel((void **)&max->path);
	closedir(dir);
}

void	frefre(void *elem)
{
	ft_memdel((void **)&((t_finfo *)elem)->link);
	ft_memdel((void **)&((t_finfo *)elem)->n_id_user);
	ft_memdel((void **)&((t_finfo *)elem)->n_id_group);
	ft_memdel((void **)&elem);
}
