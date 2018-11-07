/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:11:42 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 04:22:28 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **begin_lst, t_list *new)
{
	t_list	*elem;

	elem = *begin_lst;
	if (!*begin_lst)
		*begin_lst = new;
	else
	{
		if (new)
		{
			while (elem->next)
				elem = elem->next;
		}
		elem->next = new;
	}
}
