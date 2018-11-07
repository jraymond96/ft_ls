/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:05:09 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 16:48:43 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	const char		*csrc;

	cdest = (unsigned char*)dest;
	csrc = (const char*)src;
	while (n != 0)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
		n--;
	}
	return ((void*)dest);
}
