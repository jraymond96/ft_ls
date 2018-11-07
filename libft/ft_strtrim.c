/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:24:36 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/28 13:31:33 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whiteword(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	int		lenght;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	lenght = ft_strlen(s);
	end = 0;
	while (s[start] && ft_whiteword(s[start]))
		start++;
	if (start == lenght)
		return (ft_strnew(0));
	while (ft_whiteword(s[lenght - end - 1]) && lenght - end - 1 > 0)
		end++;
	return (ft_strsub(s, start, lenght - end - start));
}
