/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:24:42 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 16:47:53 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countint(long long n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	n < 0 ? len++ : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len++);
}

char	*ft_lltoa(long long n)
{
	int		len;
	char	*buf;
	int		sign;

	len = ft_countint(n);
	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	buf[len] = '\0';
	len--;
	sign = (n < 0) ? 1 : 0;
	while (len >= 0)
	{
		buf[len] = ft_llabs(n % 10) + '0';
		len--;
		n /= 10;
	}
	sign == 1 ? buf[0] = '-' : 0;
	return (buf);
}
