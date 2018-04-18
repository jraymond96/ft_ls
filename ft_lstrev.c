/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 08:32:57 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/18 08:43:43 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	ft_lstrev(t_list *begin_list, t_list *new_lst)
{
	t_list	*elem;

	elem = begin_list;
	if (elem->next)
		ft_lstrev(elem->next);
	while (new_lst->next)
		new_lst = new_lst->next;
	new_lst->next = ft_memmove(new_lst->next, elem, sizeof(t_list))
}
