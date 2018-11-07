/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:24:48 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 17:48:28 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padd_numbaddr(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{
	char	zerox[3];
	char	sp;
	char	zero;

	ft_strcpy(zerox, "0x");
	sp = ' ';
	zero = '0';
	if (!(elem->flags & MINUS))
	{
		ft_handle_overflow(elem, &sp, nbca->width, 1);
		ft_handle_overflow(elem, zerox, 2, 2);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
	}
	else
	{
		ft_handle_overflow(elem, zerox, 2, 2);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	}
}

int		ft_hexa_len(unsigned long arg, t_printf *elem)
{
	int	len;

	len = 0;
	if (!(arg))
		return ((elem->flags & PRECI && elem->precision == 0) ? 2 : 3);
	while (arg)
	{
		arg /= 16;
		len++;
	}
	return (len);
}

void	ft_nulladdr(t_printf *elem, t_nbcaddpw *nbca, int len, char *numb)
{
	ft_bzero(nbca, sizeof(t_nbcaddpw));
	if (elem->flags & PRECI)
	{
		*numb = !(elem->precision) ? '\0' : '0';
		nbca->preci = (elem->precision) ? (elem->precision - 1) : 0;
	}
	if (elem->flags & ZERO && elem->width)
		nbca->preci = (elem->width <= len) ? 0 : (elem->width - len);
	else if (elem->width)
		nbca->width = (elem->width <= len) ? 0 : (elem->width - len);
}

void	ft_nbcadd_addr(t_printf *elem, t_nbcaddpw *nbca, int len)
{
	int	size;

	ft_bzero(nbca, sizeof(t_nbcaddpw));
	if (elem->flags & PRECI)
		nbca->preci = (elem->precision <= len) ? 0 : (elem->precision - len);
	if (elem->width)
	{
		size = (len + 2) + nbca->preci;
		nbca->width = (elem->width <= size) ? 0 : (elem->width - size);
	}
}

int		ft_param_address(t_printf *elem, va_list ap)
{
	unsigned long	arg;
	char			*numb;
	t_nbcaddpw		nbca;
	int				len;

	arg = va_arg(ap, unsigned long);
	len = ft_hexa_len(arg, elem);
	numb = ft_ulltoa_base(arg, 16);
	if (!(arg))
		ft_nulladdr(elem, &nbca, len, numb);
	else
		ft_nbcadd_addr(elem, &nbca, len);
	ft_padd_numbaddr(elem, &nbca, numb);
	ft_memdel((void *)&numb);
	return (0);
}
