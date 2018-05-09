/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_allparam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 06:30:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 06:41:35 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printinfo(t_finfo *info, t_lenmax *max)
{
	int	padd;

	if (max->flags & MIN_A || info->name[0] != '.')
	{
		padd = ft_ilen(info->n_link);
		padd = max->lenmax_link - padd + 12;
		ft_printf("%-*s%d ", padd, info->mode, info->n_link);
		ft_printf("%-*s", (max->lenmax_u + 2), info->n_id_user);
		ft_printf("%-*s", (max->lenmax_g + 2), info->n_id_group);
		ft_printf("%*d ", max->lenmax_oct, info->size);
		ft_printf("%s ", info->timeday);
		if (info->link)
		{
			ft_printf("%s", info->name);
			ft_printf(" -> %s\n", info->link);
		}
		else
			ft_printf("%s\n", info->name);
	}
}

void	frefre(t_finfo *elem)
{
	ft_memdel((void **)&elem->link);
	ft_memdel((void **)&elem->n_id_user);
	ft_memdel((void **)&elem->n_id_group);
}

int		ft_empty_f_info(t_finfo *file_st, t_btree *root, t_lenmax *max)
{
	struct stat	allstats;
	int			len;

	if ((ft_call_stat(&allstats, max->flags, root->ptrdata)) == -1)
		return (-1);
	file_st->name = root->ptrdata;
	file_st->link = ft_handle_link(root->ptrdata);
	if ((len = ft_ilen(allstats.st_nlink)) > max->lenmax_link)
		max->lenmax_link = len;
	file_st->n_link = allstats.st_nlink;
	ft_file_time(&allstats, file_st);
	ft_handle_mode(&allstats, file_st);
	ft_file_size(&allstats, file_st, max);
	ft_find_uid_gid(&allstats, file_st, max);
	return (0);
}

void	ft_call_file(t_btree *root, int flags)
{
	t_lenmax	max;
	t_finfo		file_st;

	ft_bzero(&max, sizeof(t_lenmax));
	ft_bzero(&file_st, sizeof(t_finfo));
	if (root->left && !(flags & MIN_R))
		ft_call_file(root->left, flags);
	else if (root->right && flags & MIN_R)
		ft_call_file(root->right, flags);
	if (ft_empty_f_info(&file_st, root, &max) == 0)
	{
		if (MIN_L & flags)
			ft_printinfo(&file_st, &max);
		else
			ft_putendl(file_st.name);
		frefre(&file_st);
	}
	if (root->right && !(flags & MIN_R))
		ft_call_file(root->right, flags);
	else if (root->left && flags & MIN_R)
		ft_call_file(root->left, flags);
}
