/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:28:37 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/19 20:28:55 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_print(t_b_list *begin_list)
{
	t_bis_list	*list;

	list = begin_list->first_element;
	if (list)
	{
		while (list)
		{
			ft_putstr((char*)list->data);
			list = list->next;
		}
	}
}
