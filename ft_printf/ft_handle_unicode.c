/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:45:03 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 17:41:11 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unicodelen(wchar_t unicode)
{
	if ((unicode > 55295 && unicode < 57344) || unicode > 1114111 ||
			(MB_CUR_MAX <= 1 && unicode > 255) || unicode < 0)
		return (-1);
	else if ((unicode >= 0 && unicode <= 127) || (unicode > 127 &&
			unicode < 255 && MB_CUR_MAX == 1))
		return (1);
	else if (unicode >= 128 && unicode <= 2047)
		return (2);
	else if (unicode >= 2048 && unicode <= 65535)
		return (3);
	else
		return (4);
}

int		ft_howunicode_print(t_printf *elem, wchar_t *unicode, int *nb)
{
	int	i;
	int	res;

	i = 0;
	res = ft_unicodelen(unicode[i]);
	while (unicode[i])
	{
		if (elem->flags & PRECI && *nb >= elem->precision)
			break ;
		if (res == -1)
			return (-1);
		*nb += res;
		i++;
		res = ft_unicodelen(unicode[i]);
	}
	if (elem->flags & PRECI && *nb > elem->precision)
		*nb -= ft_unicodelen(unicode[--i]);
	return (i);
}

int		null_uni(t_printf *elem, int nb)
{
	nb = ft_howchar_add(elem, 6);
	if (elem->flags & ZERO || !(elem->flags & MINUS))
		ft_addstr_no_minus(elem, "(null)", nb);
	else
		ft_addstr_with_minus(elem, "(null)", nb);
	return (0);
}

int		ft_handle_unicode(t_printf *elem, va_list ap)
{
	wchar_t *unicode;
	char	str[5];
	int		nb;
	int		nbuni_print;
	int		i;

	nb = 0;
	i = -1;
	if (!(unicode = va_arg(ap, wchar_t*)))
		return (null_uni(elem, nb));
	ft_bzero(str, 5);
	if ((nbuni_print = ft_howunicode_print(elem, unicode, &nb)) == -1)
		return (-1);
	elem->flags & PRECI ? elem->flags ^= PRECI : 0;
	nb = ft_howchar_add(elem, nb);
	if ((elem->flags & ZERO || !(elem->flags & MINUS)) && nb)
		ft_addstr_no_minus(elem, str, nb);
	while (++i < nbuni_print)
	{
		unicode_to_str(unicode[i], str);
		ft_handle_overflow(elem, str, ft_strlen(str), 2);
		ft_bzero(str, 5);
	}
	(elem->flags & MINUS && nb) ? ft_addstr_with_minus(elem, str, nb) : 0;
	return (0);
}
