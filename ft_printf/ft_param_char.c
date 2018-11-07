/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:56:05 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/31 16:13:43 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handlechar_null(t_printf *elem, int nb_c_add, char *str)
{
	if (elem->flags & ZERO || !(elem->flags & MINUS))
	{
		ft_addstr_no_minus(elem, str, nb_c_add);
		ft_handle_overflow(elem, &str[0], 1, 1);
	}
	else
	{
		ft_handle_overflow(elem, &str[0], 1, 1);
		ft_addstr_with_minus(elem, str, nb_c_add);
	}
}

int		ft_handle_unicode_char(t_printf *elem, va_list ap)
{
	wchar_t	unicode;
	int		nb_c_add;
	char	str[5];

	unicode = va_arg(ap, wchar_t);
	nb_c_add = ft_unicodelen(unicode);
	if (nb_c_add == -1)
		return (-1);
	nb_c_add = elem->width > nb_c_add ? elem->width - nb_c_add : 0;
	ft_bzero(str, 5);
	unicode_to_str(unicode, str);
	if (str[0] == '\0')
		ft_handlechar_null(elem, nb_c_add, str);
	else if ((elem->flags & ZERO || !(elem->flags & MINUS)) && nb_c_add)
		ft_addstr_no_minus(elem, str, nb_c_add);
	else
		ft_addstr_with_minus(elem, str, nb_c_add);
	return (0);
}

int		ft_param_char(t_printf *elem, va_list ap)
{
	char	n[2];
	int		nb_c_add;
	char	unicode[5];

	ft_bzero(unicode, 5);
	ft_bzero(n, 2);
	(elem->flags & MINUS && elem->flags & ZERO) ? elem->flags ^= ZERO : 0;
	elem->flags & PRECI ? elem->flags ^= PRECI : 0;
	if (elem->type == 'C' || elem->size & L)
	{
		nb_c_add = ft_handle_unicode_char(elem, ap);
		return (nb_c_add);
	}
	n[0] = (char)va_arg(ap, int);
	nb_c_add = ft_howchar_add(elem, 1);
	if (n[0] == 0)
		ft_handlechar_null(elem, nb_c_add, n);
	else if (elem->flags & ZERO || !(elem->flags & MINUS))
		ft_addstr_no_minus(elem, n, nb_c_add);
	else
		ft_addstr_with_minus(elem, n, nb_c_add);
	return (0);
}
