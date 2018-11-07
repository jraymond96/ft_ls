/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:55:59 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/08 16:46:03 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_param_unsigned(t_printf *elem, va_list ap)
{
	uintmax_t	arg;
	char		*numb;
	t_nbcaddpw	nbca;

	arg = ft_handle_usize(elem, ap);
	numb = ft_ulltoa(arg);
	if (elem->flags & ZERO && (elem->flags & MINUS || elem->flags & PRECI))
		elem->flags ^= ZERO;
	elem->flags & MORE ? elem->flags ^= MORE : 0;
	elem->flags & SPACE ? elem->flags ^= SPACE : 0;
	nb_c_add_pw(&nbca, elem, ft_uilen(arg), numb);
	ft_handle_sign(elem, &nbca, numb);
	if (arg == 0 && elem->flags & PRECI && elem->precision == 0)
	{
		ft_padding_numbnull(elem, &nbca);
		return (0);
	}
	ft_padding_numbposi(elem, &nbca, numb);
	ft_memdel((void**)&numb);
	return (0);
}
