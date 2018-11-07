/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:39:39 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/16 16:37:05 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*bis_dest;
	char	*bis_src;

	bis_src = (char*)src;
	bis_dest = dest;
	if (n == 0)
		return (dest);
	while (n != 0 && *bis_src)
	{
		*bis_dest = *bis_src;
		bis_src++;
		bis_dest++;
		n--;
	}
	if (*bis_src == '\0' && n != 0)
	{
		ft_bzero(bis_dest, n);
		return (dest);
	}
	return (dest);
}
