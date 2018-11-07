/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:53:25 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 22:32:26 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ll(t_printf *elem, va_list ap)
{
	long long	arg;

	arg = va_arg(ap, long long);
	if (elem->size & HH)
		ft_print_binary(elem, arg, sizeof(char));
	else if (elem->size & H)
		ft_print_binary(elem, arg, sizeof(short));
	else if (elem->size & L)
		ft_print_binary(elem, arg, sizeof(int));
	else
		ft_print_binary(elem, arg, sizeof(long));
}

int		ft_param_binary(t_printf *elem, va_list ap)
{
	unsigned long long	u_arg;

	if (!(elem->size & LL))
		ft_ll(elem, ap);
	else
	{
		u_arg = va_arg(ap, unsigned long long);
		if (elem->size & HH)
			ft_print_ubinary(elem, u_arg, sizeof(char));
		else if (elem->size & H)
			ft_print_ubinary(elem, u_arg, sizeof(short));
		else if (elem->size & L)
			ft_print_ubinary(elem, u_arg, sizeof(int));
		else
			ft_print_ubinary(elem, u_arg, sizeof(long));
	}
	return (0);
}
