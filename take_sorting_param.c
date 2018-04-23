/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sorting_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 01:43:47 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/23 15:50:08 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_btree	*ft_sorting_param(char const **argv, int flags)
{
	struct stat		stats;
	t_btree			*root;
	int				x;
	int				len;
	char 			*path;

	x = 1;
	root = NULL;
	while (argv[x] && argv[x][0] == '-')
	{
		if (argv[x][1] == '-')
		{
			x++;
			break;
		}
		x++;
	}
	while (argv[x])
	{
		path = ft_strdup(argv[x]);
		if (ft_call_stat(&stats, flags, path) == 0)
		{
			len = ft_strlen(path) + 1;
			if (S_ISDIR(stats.st_mode))
				root = ft_btree_start(root, path, len, 1);
			else
				root = ft_btree_start(root, path, len, 0);
		}
		ft_memdel((void **)&path);
		x++;
	}
	return (root);
}
