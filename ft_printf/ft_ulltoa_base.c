/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:35:31 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 16:46:11 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ullcountint(unsigned long long nb, int base)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len++);
}

char	*ft_ulltoa_base(unsigned long long nb, int base)
{
	int		len;
	char	*buf;
	char	rest[17];

	ft_strcpy(rest, "0123456789abcdef");
	len = ft_ullcountint(nb, base);
	if (!(buf = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	buf[len] = '\0';
	len--;
	while (len >= 0)
	{
		buf[len] = rest[ft_llabs((nb % base))];
		len--;
		nb /= base;
	}
	return (buf);
}
