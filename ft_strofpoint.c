/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strofpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 05:11:39 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/02 17:42:40 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_how_arg(char **argv)
{
	int	x;
	int	res;

	x = 1;
	res = 0;
	while (argv[x] && argv[x][0] == '-')
		x++;
	while (argv[x++])
		res++;
	return (res);
}

int		ft_how_dir(t_btree *root, int i)
{
	i++;
	if (root->left)
		i = ft_how_dir(root->left, i);
	if (root->right)
		i = ft_how_dir(root->right, i);
	return (i);
}

int		is_empty(t_btree *root, int i)
{
	if (root->left)
	{
		if (((t_finfo *)root->ptrdata)->name[0] != '.')
			i++;
		i = ft_how_dir(root->left, i);
	}
	if (root->right)
	{
		if (((t_finfo *)root->ptrdata)->name[0] != '.')
			i++;
		i = ft_how_dir(root->right, i);
	}
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
