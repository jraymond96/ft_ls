/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:17:10 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/16 16:36:01 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*idest;

	idest = dest;
	while (*idest)
		idest++;
	while (n && *src)
	{
		*idest = *src;
		idest++;
		src++;
		n--;
	}
	*idest = '\0';
	return (dest);
}
