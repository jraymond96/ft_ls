/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:41:13 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/16 16:27:11 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*bis_dest;
	int		i;
	int		size;

	size = ft_strlen(src);
	bis_dest = dest;
	i = ft_strlen(dest);
	ft_memcpy((bis_dest + i), src, ft_strlen(src));
	bis_dest[i + size] = '\0';
	return (dest);
}
