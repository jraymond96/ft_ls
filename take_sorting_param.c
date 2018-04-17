/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sorting_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 01:43:47 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/17 06:33:48 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_file_type(struct stat *allstats);

t_btree	*ft_sorting_param(char const **argv)
{
	struct stat		stats;
	t_btree			*root;
	int				x;
	int				len;
	char 			*path;

	x = 1;
	root = NULL;
	while (argv[x][0] == '-')
		x++;
	while (argv[x])
	{
		path = ft_strdup("/");
		path = ft_strjoin_free(path, argv[x], 1);
		lstat(path, &stats);
		len = ft_strlen(argv[x]) + 1;
		ft_putchar(ft_file_type(&stats));
		if (S_ISDIR(stats.st_mode))
		{
			ft_putendl("toc");
			root = ft_btree_start(root, (char *)argv[x], len, 1);
		}
		else
			root = ft_btree_start(root, (char *)argv[x], len, 0);
		ft_memdel((void **)&path);
		x++;
	}
	return (root);
}
