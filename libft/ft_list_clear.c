/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:13:32 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/19 20:23:09 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_b_list **begin_list)
{
	t_bis_list	*list;
	t_bis_list	*tmp;

	list = (*begin_list)->first_element;
	while (list && list->next)
	{
		tmp = list->next;
		free(list);
		list = tmp->next;
	}
	free(*begin_list);
	(*begin_list) = NULL;
}
