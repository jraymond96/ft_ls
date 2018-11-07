/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:41:43 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/16 16:05:57 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char *isrc;
	unsigned char ic;

	isrc = (unsigned char*)src;
	ic = (unsigned char)c;
	while (len)
	{
		if (*isrc == ic)
			return (isrc);
		isrc++;
		len--;
	}
	return (NULL);
}
