/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 03:14:24 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/14 07:45:52 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_empty_f_info(t_finfo *file_st, t_btree *root, t_lenmax *max)
{
	struct stat	allstats;
	int			len;

	if ((call_lstat(&allstats, ((t_infp *)root->ptrdata)->name)) == -1)
		return (-1);
	file_st->name = ((t_infp *)root->ptrdata)->name;
	file_st->link = ft_handle_link(((t_infp *)root->ptrdata)->name);
	if ((len = ft_ilen(allstats.st_nlink)) > max->lenmax_link)
		max->lenmax_link = len;
	file_st->n_link = allstats.st_nlink;
	ft_file_time(&allstats, file_st, max->flags);
	ft_handle_mode(&allstats, file_st);
	ft_file_size(&allstats, file_st, max);
	ft_find_uid_gid(&allstats, file_st, max);
	file_st->max = max;
	return (0);
}

t_btree	*parsing_files(t_btree *root, int flags, t_lenmax *max, t_btree *rinfo)
{
	t_finfo	info;

	ft_bzero(&info, sizeof(t_finfo));
	if (root->left)
		rinfo = parsing_files(root->left, flags, max, rinfo);
	if (ft_empty_f_info(&info, root, max) == -1)
		ft_printf("ls: %s\n", strerror(errno));
	else
		rinfo = ft_btreeinser(rinfo, &info, sizeof(t_finfo), ptrcmp(flags));
	if (root->right)
		rinfo = parsing_files(root->right, flags, max, rinfo);
	return (rinfo);
}

void	call_files(t_btree *root, int flags)
{
	t_lenmax	max;
	t_btree		*root_inf;
	void		*ptr;

	root_inf = NULL;
	ptr = frefre;
	ft_bzero(&max, sizeof(t_lenmax));
	root_inf = parsing_files(root, flags, &max, root_inf);
	if (flags & MIN_R)
	{
		if (flags & MIN_L)
			ft_revbrowsetree(root_inf, lprint);
		else
			ft_revbrowsetree(root_inf, simpleprint);
	}
	else
	{
		if (flags & MIN_L)
			ft_browsetree(root_inf, lprint);
		else
			ft_browsetree(root_inf, simpleprint);
	}
	ft_btreedel(&root_inf, ptr);
}
