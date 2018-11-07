/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:40:33 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/14 18:40:37 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_cut(char *str, char const *src, char c)
{
	int		cut;

	cut = 0;
	while (*src && *src != c)
	{
		*str = *src;
		str++;
		src++;
		cut++;
	}
	*str = '\0';
	return (cut);
}

static int		ft_str_len(char const *str, char c)
{
	int		len;

	len = 0;
	while (*str && *str != c)
	{
		str++;
		len++;
	}
	return (len);
}

static int		ft_howchaine(char const *str, char c)
{
	int		len;

	len = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			len++;
		while (*str && *str != c)
			str++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**s1;
	int		i;

	if (!s)
		return (NULL);
	s1 = (char**)malloc(sizeof(*s1) * (ft_howchaine(s, c) + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		s1[i] = (char*)malloc(sizeof(**s1) * (ft_str_len(s, c) + 1));
		if (!s1[i])
			return (NULL);
		s = s + ft_nb_cut(s1[i], s, c);
		i++;
		while (*s && *s == c)
			s++;
	}
	s1[i] = 0;
	return (s1);
}
