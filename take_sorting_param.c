/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sorting_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 01:43:47 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/13 02:33:52 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		skip_flags(char const **argv)
{
	int	x;

	x = 1;
	while (argv[x] && argv[x][0] == '-')
	{
		if (argv[x][1] == '-')
		{
			x++;
			break ;
		}
		x++;
	}
	return (x);
}

t_btree	*ft_sorting_param(char const **argv, int flags)
{
	struct stat		stats;
	t_btree			*root;
	int				x;
	t_choose		info;
	char			*path;

	x = skip_flags(argv);
	root = NULL;
	while (argv[x])
	{
		ft_bzero(&info, sizeof(t_choose));
		path = ft_strdup(argv[x++]);
		info.flags = flags;
		if (call_lstat(&stats, path) == 0)
		{
			info.stats = &stats;
			if (S_ISDIR(stats.st_mode))
				root = ft_btree_start(root, &info, path, 1);
			else
				root = ft_btree_start(root, &info, path, 0);
		}
		ft_memdel((void **)&path);
	}
	return (root);
}
