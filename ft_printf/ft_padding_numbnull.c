/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_numbnull.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:12:57 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 17:43:48 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding_numbnull(t_printf *elem, t_nbcaddpw *nbca)
{
	char	sp;
	char	more;

	sp = ' ';
	more = '+';
	if (elem->flags & PRECI && !(elem->precision) && elem->width)
		nbca->width++;
	if (elem->flags & MINUS)
	{
		ft_handle_overflow(elem, &sp, nbca->width, 1);
		if (elem->flags & MORE)
			ft_handle_overflow(elem, &more, 1, 1);
	}
	else
	{
		if (elem->flags & MORE)
			ft_handle_overflow(elem, &more, 1, 1);
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	}
}

void	nb_c_addoctnull_pw(t_nbcaddpw *nbca, t_printf *elem)
{
	int			i;

	ft_bzero(nbca, sizeof(t_nbcaddpw));
	if (elem->flags & PRECI && elem->flags & SHARP)
		nbca->preci = (0 >= elem->precision) ? 1 : elem->precision;
	else if (elem->flags & PRECI && !(elem->flags & SHARP))
		nbca->preci = (0 >= elem->precision) ? 0 : elem->precision;
	else if (!(elem->flags & PRECI))
		nbca->preci = 1;
	i = nbca->preci;
	if (elem->width)
		nbca->width = elem->width <= i ? 0 : (elem->width - i);
}

int		ft_paddoct_null(t_printf *elem, t_nbcaddpw *nbca)
{
	char	sp;
	char	zero;

	sp = ' ';
	zero = '0';
	nb_c_addoctnull_pw(nbca, elem);
	if (elem->flags & ZERO || !(elem->flags & MINUS))
	{
		if (!(elem->flags & ZERO))
			ft_handle_overflow(elem, &sp, nbca->width, 1);
		else
			ft_handle_overflow(elem, &zero, nbca->width, 1);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
	}
	else
	{
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	}
	return (0);
}
