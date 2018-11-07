/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:44:03 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/01 11:49:24 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ilen(intmax_t arg)
{
	int			i;
	intmax_t	res;

	i = 0;
	res = arg;
	if (res == 0)
		return (1);
	while (res)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

int		ft_uilen(uintmax_t arg)
{
	int			i;
	uintmax_t	res;

	i = 0;
	res = arg;
	if (res == 0)
		return (1);
	while (res)
	{
		res = res / 10;
		i++;
	}
	return (i);
}
