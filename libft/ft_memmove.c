/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 00:14:53 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/16 16:25:08 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i--)
		{
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
		}
	}
	return (dest);
}
