/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:15:58 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 17:24:26 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_abs(int nb)
{
	return (nb = (nb < 0) ? -nb : nb);
}

long long	ft_llabs(long long nb)
{
	return (nb = (nb < 0) ? -nb : nb);
}