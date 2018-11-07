/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:42:26 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/14 18:42:29 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_countint(int n)
{
	long	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len++);
}

static int		ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	long	n_lenght;
	long	len;
	char	*buf;

	n_lenght = n;
	len = ft_countint(n_lenght);
	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	buf[len] = '\0';
	len--;
	if (n_lenght < 0)
		n_lenght = -n_lenght;
	while (len >= 0)
	{
		buf[len] = (n_lenght % 10) + '0';
		len--;
		n_lenght /= 10;
	}
	if (ft_sign(n))
		buf[0] = '-';
	return (buf);
}
