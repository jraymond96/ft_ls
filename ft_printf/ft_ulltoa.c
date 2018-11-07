/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:05:41 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 18:36:50 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countull(unsigned long long n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len++);
}

char	*ft_ulltoa(unsigned long long n)
{
	int					len;
	char				*buf;

	len = ft_countull(n);
	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	buf[len] = '\0';
	len--;
	while (len >= 0)
	{
		buf[len] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (buf);
}
