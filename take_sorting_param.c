/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sorting_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 01:43:47 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/22 07:33:16 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_btree	*ft_sorting_param(char const **argv)
{
	struct stat		stats;
	t_btree			*root;
	int				x;
	int				len;
	char 			*path;

	x = 1;
	root = NULL;
	while (argv[x] && argv[x][0] == '-')
		x++;
	while (argv[x])
	{
		path = ft_strdup(argv[x]);
		if (stat(path, &stats) == -1)
		{
			path = ft_strjoin_free("ls: ", path, 2);
			perror(path);
		}
		else
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
