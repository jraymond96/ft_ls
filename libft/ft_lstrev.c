/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 03:40:48 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 22:47:52 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_recurlst(t_list *begin, t_list *last_elem)
{
	t_list	*tmp;

	tmp = last_elem;
	if (!begin)
		return (NULL);
	if (begin->next != last_elem)
		ft_recurlst(begin->next, last_elem);
	while (last_elem->next)
		last_elem = last_elem->next;
	last_elem->next = begin;
	begin->next = NULL;
	return (tmp);
}

t_list	*ft_lstrev(t_list *begin)
{
	t_list	*elem;

	if (!(elem = begin))
		return (NULL);
	while (elem->next)
		elem = elem->next;
	return (ft_recurlst(begin, elem));
}
