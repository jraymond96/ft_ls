/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:51:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 18:26:16 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nb_c_addhexa_pw(t_nbcaddpw *nbca, t_printf *elem, int intl)
{
	int			i;

	ft_bzero(nbca, sizeof(t_nbcaddpw));
	if (elem->flags & PRECI)
		nbca->preci = (intl >= elem->precision) ? 0 : elem->precision - intl;
	i = nbca->preci;
	if (elem->width)
	{
		if (elem->width <= (i + intl))
			nbca->width = 0;
		else
			nbca->width = elem->width - (i + intl);
	}
}

void	ft_nominus(t_printf *elem, t_nbcaddpw *nbca, char *numb, uintmax_t arg)
{
	char	sp;
	char	zero;
	char	sharp[3];

	sp = ' ';
	zero = '0';
	elem->type == 'X' ? ft_strcpy(sharp, "0X") : ft_strcpy(sharp, "0x");
	if (!(elem->flags & ZERO))
	{
		ft_handle_overflow(elem, &sp, nbca->width, 1);
		if (elem->flags & SHARP && arg != 0)
			ft_handle_overflow(elem, sharp, 2, 2);
	}
	else
	{
		if (elem->flags & SHARP && arg != 0)
			ft_handle_overflow(elem, sharp, 2, 2);
		ft_handle_overflow(elem, &zero, nbca->width, 1);
	}
	ft_handle_overflow(elem, &zero, nbca->preci, 1);
	ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
}

void	ft_paddnum(t_printf *elem, t_nbcaddpw *nbca, char *numb, uintmax_t arg)
{
	char	sp;
	char	zero;
	char	sharp[3];

	sp = ' ';
	zero = '0';
	elem->type == 'X' ? ft_strcpy(sharp, "0X") : ft_strcpy(sharp, "0x");
	if (elem->flags & ZERO || !(elem->flags & MINUS))
		ft_nominus(elem, nbca, numb, arg);
	else
	{
		if (elem->flags & SHARP && arg != 0)
			ft_handle_overflow(elem, sharp, 2, 2);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	}
}

void	ft_mintomaj(char *numb)
{
	int	i;

	i = 0;
	while (numb[i])
	{
		if (numb[i] >= 97 && numb[i] <= 122)
			numb[i] ^= (1 << 5);
		i++;
	}
}

int		ft_param_hexa(t_printf *elem, va_list ap)
{
	uintmax_t	arg;
	char		*numb;
	t_nbcaddpw	nbca;
	char		space;

	space = ' ';
	arg = ft_handle_uhexasize(elem, ap);
	numb = ft_ulltoa_base(arg, 16);
	if (elem->flags & ZERO && (elem->flags & MINUS || elem->flags & PRECI))
		elem->flags ^= ZERO;
	nb_c_addhexa_pw(&nbca, elem, ft_strlen(numb));
	if (elem->flags & PRECI && elem->precision == 0 && arg == 0)
	{
		ft_handle_overflow(elem, &space, elem->width, 1);
		return (0);
	}
	if (elem->flags & SHARP && arg != 0)
		(nbca.width - 2) >= 0 ? nbca.width -= 2 : nbca.width == 0;
	if (elem->type == 'X')
		ft_mintomaj(numb);
	ft_paddnum(elem, &nbca, numb, arg);
	ft_memdel((void**)&numb);
	return (0);
}
