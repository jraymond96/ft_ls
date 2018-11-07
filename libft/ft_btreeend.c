/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:52:01 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/13 09:07:14 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	min_max : -1 for get min value and other for get max value of binary tree
*/

#include "libft.h"

t_btree	*ft_btreeend(t_btree *root, int min_max)
{
	if (!root)
		return (NULL);
	if (min_max == -1)
	{
		while (root->left)
			root = root->left;
	}
	else
	{
		while (root->right)
			root = root->right;
	}
	return (root);
}
