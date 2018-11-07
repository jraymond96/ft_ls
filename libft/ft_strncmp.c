/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:20:40 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/15 17:09:29 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	else
		while (*s1 && *s2 && --n && ((unsigned char)*s1 == (unsigned char)*s2))
		{
			s1++;
			s2++;
		}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
