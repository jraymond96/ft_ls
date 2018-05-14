/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strofpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 05:11:39 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/14 08:55:25 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_empty(t_btree *root, int i)
{
	if (((t_finfo *)root->ptrdata)->name[0] != '.')
		i++;
	if (root->left)
		i = is_empty(root->left, i);
	if (root->right)
		i = is_empty(root->right, i);
	return (i);
}

int		ft_strofpoint(char *str)
{
	while (*str)
	{
		if (*str != '.')
			return (-1);
		str++;
	}
	return (0);
}

char	*tname_file(char *str)
{
	char	*tmp;

	while ((str = ft_strchr(str, '/')))
	{
		str++;
		tmp = str;
	}
	return (tmp);
}
