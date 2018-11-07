/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:49:09 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 18:29:04 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nb_c_addoct_pw(t_nbcaddpw *nbca, t_printf *elem, int intl)
{
	int			i;

	ft_bzero(nbca, sizeof(t_nbcaddpw));
	if (elem->flags & PRECI)
		nbca->preci = (intl >= elem->precision) ? 0 : elem->precision - intl;
	i = nbca->preci;
	if (elem->width)
	{
		if (elem->flags & SHARP)
			i++;
		if (elem->width <= (i + intl))
			nbca->width = 0;
		else
			nbca->width = elem->width - (i + intl);
	}
}

void	ft_padding_numb(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{
	char	sp;
	char	zero;

	sp = ' ';
	zero = '0';
	if (elem->flags & ZERO || !(elem->flags & MINUS))
	{
		if (!(elem->flags & ZERO))
			ft_handle_overflow(elem, &sp, nbca->width, 1);
		else
			ft_handle_overflow(elem, &zero, nbca->width, 1);
		if (elem->flags & SHARP)
			ft_handle_overflow(elem, &zero, 1, 1);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
	}
	else
	{
		if (elem->flags & SHARP)
			ft_handle_overflow(elem, &zero, 1, 1);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	}
}

void	ft_handle_sharp(t_nbcaddpw *nbca, t_printf *elem, unsigned long long nb)
{
	if (elem->flags & SHARP && elem->flags & MINUS && nb != 0)
	{
		if (nbca->preci > 0 && !(nbca->width))
			nbca->preci -= 1;
		else
			nbca->width = (nbca->width - 1) < 0 ? 0 : nbca->width--;
	}
	else if (elem->flags & SHARP && nb != 0)
	{
		if (nbca->preci > 0 && !(nbca->width))
			nbca->preci -= 1;
		else
			nbca->width = (nbca->width - 1) < 0 ? 0 : nbca->width--;
	}
}

int		ft_param_octal(t_printf *elem, va_list ap)
{
	unsigned long long	arg;
	char				*numb;
	t_nbcaddpw			nbca;

	arg = ft_handle_uoctsize(elem, ap);
	numb = ft_ulltoa_base(arg, 8);
	if (elem->flags & ZERO && (elem->flags & MINUS || elem->flags & PRECI))
		elem->flags ^= ZERO;
	nb_c_addoct_pw(&nbca, elem, ft_strlen(numb));
	ft_handle_sharp(&nbca, elem, arg);
	if (arg == 0)
		return (ft_paddoct_null(elem, &nbca));
	ft_padding_numb(elem, &nbca, numb);
	ft_memdel((void**)&numb);
	return (0);
}
