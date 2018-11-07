/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 23:43:02 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 22:00:00 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_param_n(t_printf *elem, va_list ap)
{
	void	*ptr;

	if (!(ptr = va_arg(ap, void *)))
		return ;
	if (elem->size & J)
		*((intmax_t *)ptr) = ((intmax_t)(elem->i_buff + elem->ret));
	else if (elem->size & Z)
		*((size_t *)ptr) = ((size_t)(elem->i_buff + elem->ret));
	else if (elem->size & LL)
		*((long long *)ptr) = ((long long)(elem->i_buff + elem->ret));
	else if (elem->size & L)
		*((long *)ptr) = ((long)(elem->i_buff + elem->ret));
	else if (elem->size & H)
		*((signed char *)ptr) = ((signed char)(elem->i_buff + elem->ret));
	else if (elem->size & HH)
		*((short *)ptr) = ((short)(elem->i_buff + elem->ret));
	else
		*((int *)ptr) = ((int)(elem->i_buff + elem->ret));
}
