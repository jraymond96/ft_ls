/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreelen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 07:07:39 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/13 08:13:49 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btreelen(t_btree *root, int *i)
{
	*i += 1;
	if (root->left)
		*i = ft_btreelen(root->left, i);
	if (root->right)
		*i = ft_btreelen(root->right, i);
	return (*i);
}
