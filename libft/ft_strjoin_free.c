/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:16:01 by jraymond          #+#    #+#             */
/*   Updated: 2017/12/20 19:51:03 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int i)
{
	char	*result_join;

	result_join = ft_strjoin(s1, s2);
	if (i == 0 || i == 1)
	{
		free((void*)s1);
		s1 = NULL;
	}
	if (i == 0 || i == 2)
	{
		free((void*)s2);
		s2 = NULL;
	}
	return (result_join);
}
