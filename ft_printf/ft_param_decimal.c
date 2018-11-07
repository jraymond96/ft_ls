/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:59:02 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/01 11:49:11 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nb_c_add_pw(t_nbcaddpw *nbca, t_printf *elem, int intl, char *numb)
{
	int			i;

	ft_bzero(nbca, sizeof(t_nbcaddpw));
	if (elem->flags & PRECI)
		nbca->preci = (intl >= elem->precision) ? 0 : elem->precision - intl;
	i = nbca->preci;
	if (elem->width)
	{
		if (elem->flags & MORE || elem->flags & SPACE || numb[0] == '-')
			i++;
		if (elem->width <= (i + intl))
			nbca->width = 0;
		else
			nbca->width = elem->width - (i + intl);
	}
}

void	ft_handle_sign(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{
	char	sp;
	char	minus;
	char	more;

	sp = ' ';
	minus = '-';
	more = '+';
	if (numb[0] == '-')
		nbca->preci = (nbca->preci - 1) < 0 ? 0 : nbca->preci--;
	if (elem->flags & SPACE && numb[0] != '-')
	{
		ft_handle_overflow(elem, &sp, 1, 1);
		nbca->width = (nbca->width - 1) < 0 ? 0 : nbca->width--;
	}
	if (elem->flags & MORE && elem->flags & ZERO && numb[0] != '-')
	{
		ft_handle_overflow(elem, &more, 1, 1);
		nbca->width = (nbca->width - 1) < 0 ? 0 : nbca->width--;
		elem->flags ^= MORE;
	}
}

void	ft_padding_numbposi(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{
	char	sp;
	char	zero;
	char	more;

	sp = ' ';
	more = '+';
	zero = '0';
	if (elem->flags & ZERO || !(elem->flags & MINUS))
		ft_posi_no_minus(elem, nbca, numb);
	else
	{
		if (elem->flags & MORE)
			ft_handle_overflow(elem, &more, 1, 1);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	}
}

void	ft_padding_numbneg(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{
	char	sp;
	char	zero;

	sp = ' ';
	zero = '0';
	if (elem->flags & ZERO || !(elem->flags & MINUS))
		ft_neg_no_minus(elem, nbca, numb);
	else
	{
		ft_handle_overflow(elem, &numb[0], 1, 1);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		numb++;
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	}
}

int		ft_param_decimal(t_printf *elem, va_list ap)
{
	intmax_t	arg;
	char		*numb;
	t_nbcaddpw	nbca;

	arg = ft_handle_size(elem, ap);
	numb = ft_lltoa(arg);
	if (elem->flags & ZERO && (elem->flags & MINUS || elem->flags & PRECI))
		elem->flags ^= ZERO;
	(elem->flags & SPACE && elem->flags & MORE) ? elem->flags ^= SPACE : 0;
	nb_c_add_pw(&nbca, elem, ilen(arg), numb);
	ft_handle_sign(elem, &nbca, numb);
	if (arg == 0 && elem->flags & PRECI && elem->precision == 0)
	{
		ft_padding_numbnull(elem, &nbca);
		return (0);
	}
	if (numb[0] == '-')
		ft_padding_numbneg(elem, &nbca, numb);
	else
		ft_padding_numbposi(elem, &nbca, numb);
	ft_memdel((void**)&numb);
	return (0);
}
