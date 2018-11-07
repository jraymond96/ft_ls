/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:36:40 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/16 15:31:38 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*last;

	if (alst == NULL)
		return ;
	last = *alst;
	while (last != NULL)
	{
		temp = last->next;
		ft_lstdelone(&last, del);
		last = temp;
	}
	*alst = NULL;
}
