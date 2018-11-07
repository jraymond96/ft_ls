/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 08:40:59 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/10 00:59:10 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_swap(t_list **beginlst, t_list *elem, t_list *parent)
{
	t_list	*tmp;

	tmp = elem->next;
	elem->next = tmp->next;
	tmp->next = elem;
	if (parent)
		parent->next = tmp;
	else
		*beginlst = tmp;
	return (*beginlst);
}

/*
** cmp : if cmp > 0 i swap;
*/

t_list	*ft_lst_sort(t_list *b_list, int (cmp)(t_list *))
{
	t_list	*elem;
	t_list	*parent;

	elem = b_list;
	if (b_list == NULL)
		return (NULL);
	parent = NULL;
	while (elem->next)
	{
		if (cmp(elem) < 0)
		{
			elem = ft_swap(&b_list, elem, parent);
			parent = NULL;
		}
		else
		{
			parent = elem;
			elem = elem->next;
		}
	}
	return (b_list);
}
