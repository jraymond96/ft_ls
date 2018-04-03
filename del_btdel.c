/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_btdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:44:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/03 15:56:19 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"

void	del(void *elem, size_t content_size)
{
	content_size = 1;
	free(elem);
}

void	btdel(void *elem)
{
	ft_memdel((void **)&((t_finfo *)elem)->name);
	ft_memdel((void **)&((t_finfo *)elem)->n_id_user);
	ft_memdel((void **)&((t_finfo *)elem)->n_id_group);
	ft_memdel(&elem);
}
