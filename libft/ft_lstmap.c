/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:54:13 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/28 13:25:33 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*copy;

	new = NULL;
	if (lst && f)
	{
		if (!(new = f(lst)))
			return (NULL);
		copy = new;
		while (lst->next)
		{
			if (!(copy->next = f(lst->next)))
				return (NULL);
			copy = copy->next;
			lst = lst->next;
		}
	}
	return (new);
}
