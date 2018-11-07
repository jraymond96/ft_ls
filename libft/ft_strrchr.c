/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:41:04 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/16 16:07:33 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occu;

	last_occu = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_occu = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	return (last_occu);
}
