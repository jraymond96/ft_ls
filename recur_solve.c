/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 04:33:22 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/12 01:37:00 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		init_lenmax(char *path, DIR *dir, int flags, t_lenmax *max)
{
	if (!dir)
		return (ft_error(path, 3));
	ft_bzero(max, sizeof(t_lenmax));
	max->flags = flags;
	max->lenmax_mino = 3;
	ft_getinf_term(max);
	max->path = path;
	return (1);
}

t_list	*sort_list(t_list *b_list, int flags)
{
	void 	*ptr[3];
	int		x;

	ptr[0] = lst_ncmp;
	ptr[1] = lst_tcmp;
	ptr[2] = NULL;
	x = 0;
	if (flags & MIN_T || flags & MIN_U)
		x = 1;
	b_list = ft_lst_sort(b_list, ptr[x]);
	if (flags & MIN_R)
		b_list = ft_lstrev(b_list);
	return (b_list);
}

t_list	*next_free(char **all_path, char *path, t_list *elem)
{
	ft_memdel((void **)all_path);
	*all_path = path;
	return (elem->next);
}

char	*manage_path(char **all_path, char *path, t_list *elem)
{
	ft_putchar('\n');
	path = *all_path;
	*all_path = ft_strjoin(*all_path, ((t_finfo *)elem->content)->name);
	return (path);
}

int		ft_recur_solve(char *path, DIR *dir, int flags, t_recur *rec)
{
	t_btree			*root;
	t_list			*b_list;
	t_list			*elem;
	t_lenmax		lenmax;
	char			*all_path;

	b_list = NULL;
	if (!(init_lenmax(path, dir, flags, &lenmax)))
		return (0);
	root = ft_take_infofile(path, dir, &b_list, &lenmax);
	all_path = ft_strjoin(path, "/");
	elem = sort_list(b_list, flags);
	ft_print_tree(root, &lenmax, rec);
	if (flags & MAX_R)
	{
		while (elem)
		{
			path = manage_path(&all_path, path, elem);
			ft_recur_solve(all_path, opendir(all_path), flags, rec);
			elem = next_free(&all_path, path, elem);
		}
	}
	ft_free_all(&b_list, &root, dir, &all_path);
	return (0);
}
