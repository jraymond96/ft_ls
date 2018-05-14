/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 04:33:22 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/14 06:30:28 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		init_lenmax(t_recur *rec, DIR *dir, int flags, t_lenmax *max)
{
	if (!dir)
		return (ft_error(max->path, 3));
	ft_bzero(max, sizeof(t_lenmax));
	max->flags = flags;
	max->lenmax_mino = 3;
	ft_getinf_term(max);
	max->rec = rec;
	return (1);
}

void	recur(void *elem)
{
	char	*tmp;

	ft_putchar('\n');
	tmp = PATH->max->path;
	PATH->max->path = ft_strjoin(PATH->max->path, PATH->name);
	ft_recur_solve(PATH->max->path, opendir(PATH->max->path), PATH->max->flags,
					PATH->max->rec);
	ft_memdel((void **)&PATH->max->path);
	PATH->max->path = tmp;
}

int		ft_recur_solve(char *path, DIR *dir, int flags, t_recur *rec)
{
	t_btree			*root;
	t_btree			*folder;
	t_lenmax		lenmax;

	folder = NULL;
	lenmax.path = path;
	if (!(init_lenmax(rec, dir, flags, &lenmax)))
		return (0);
	lenmax.path = ft_strjoin(path, "/");
	root = ft_take_infofile(path, dir, &folder, &lenmax);
	if (root)
		ft_print_tree(root, &lenmax, rec);
	if (flags & MAX_R && folder)
	{
		if (flags & MIN_R)
			ft_revbrowsetree(folder, recur);
		else
			ft_browsetree(folder, recur);
	}
	ft_free_all(&root, &folder, dir, &lenmax);
	return (0);
}
