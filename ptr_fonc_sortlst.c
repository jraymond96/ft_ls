/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_fonc_sortlst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 00:42:50 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/10 01:52:12 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		lst_ncmp(t_list *elem)
{
	return (ft_strcmp(((t_finfo *)elem->content)->name,
				((t_finfo *)elem->next->content)->name));
}

int		lst_tcmp(t_list *elem)
{

	return (((t_finfo *)elem->content)->time_n -
				((t_finfo *)elem->next->content)->time_n);
}
