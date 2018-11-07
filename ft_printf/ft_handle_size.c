/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:31:09 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 17:28:50 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_handle_size(t_printf *elem, va_list ap)
{
	intmax_t	arg;

	if (elem->size & J && elem->type != 'D')
		arg = va_arg(ap, intmax_t);
	else if (elem->size & Z && elem->type != 'D')
		arg = va_arg(ap, size_t);
	else if (elem->size & LL && elem->type != 'D')
		arg = va_arg(ap, long long);
	else if (elem->size & L || elem->type == 'D')
		arg = va_arg(ap, long);
	else if (elem->size & H && elem->type != 'D')
		arg = (short)va_arg(ap, int);
	else if (elem->size & HH && elem->type != 'D')
		arg = (signed char)va_arg(ap, int);
	else
		arg = va_arg(ap, int);
	return (arg);
}

uintmax_t	ft_handle_usize(t_printf *elem, va_list ap)
{
	uintmax_t	arg;

	if (elem->size & J && elem->type != 'U')
		arg = va_arg(ap, uintmax_t);
	else if (elem->size & Z && elem->type != 'U')
		arg = va_arg(ap, size_t);
	else if (elem->size & LL && elem->type != 'U')
		arg = va_arg(ap, unsigned long long);
	else if (elem->size & L || elem->type == 'U')
		arg = va_arg(ap, unsigned long);
	else if (elem->size & H && elem->type != 'U')
		arg = (unsigned short)va_arg(ap, int);
	else if (elem->size & HH && elem->type != 'U')
		arg = (unsigned char)va_arg(ap, int);
	else
		arg = va_arg(ap, unsigned);
	return (arg);
}

uintmax_t	ft_handle_uoctsize(t_printf *elem, va_list ap)
{
	uintmax_t	arg;

	if (elem->size & J && elem->type != 'O')
		arg = va_arg(ap, uintmax_t);
	else if (elem->size & Z && elem->type != 'O')
		arg = va_arg(ap, size_t);
	else if (elem->size & LL && elem->type != 'O')
		arg = va_arg(ap, unsigned long long);
	else if (elem->size & L || elem->type == 'O')
		arg = va_arg(ap, unsigned long);
	else if (elem->size & H && elem->type != 'O')
		arg = (unsigned short)va_arg(ap, int);
	else if (elem->size & HH && elem->type != 'O')
		arg = (unsigned char)va_arg(ap, int);
	else
		arg = va_arg(ap, unsigned);
	return (arg);
}

uintmax_t	ft_handle_uhexasize(t_printf *elem, va_list ap)
{
	uintmax_t	arg;

	if (elem->size & J)
		arg = va_arg(ap, uintmax_t);
	else if (elem->size & Z)
		arg = va_arg(ap, size_t);
	else if (elem->size & LL)
		arg = va_arg(ap, unsigned long long);
	else if (elem->size & L)
		arg = va_arg(ap, unsigned long);
	else if (elem->size & H)
		arg = (unsigned short)va_arg(ap, int);
	else if (elem->size & HH)
		arg = (unsigned char)va_arg(ap, int);
	else
		arg = va_arg(ap, unsigned);
	return (arg);
}
