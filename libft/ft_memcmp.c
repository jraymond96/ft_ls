/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:01:04 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/16 16:22:22 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bis_s1;
	unsigned char	*bis_s2;

	bis_s1 = (unsigned char*)s1;
	bis_s2 = (unsigned char*)s2;
	while (n != 0)
	{
		if (*bis_s1 != *bis_s2)
			return (*bis_s1 - *bis_s2);
		bis_s1++;
		bis_s2++;
		n--;
	}
	return (0);
}
