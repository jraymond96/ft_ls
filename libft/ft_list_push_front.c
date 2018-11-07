/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:54:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/28 09:42:25 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_b_list **begin_list, void *data)
{
	t_bis_list	*list;

	list = ft_creat_elem(data);
	if (list)
	{
		list->next = (*begin_list)->first_element;
		(*begin_list)->first_element = list;
	}
	else
		(*begin_list)->first_element = ft_creat_elem(data);
}
