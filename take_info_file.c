/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 04:45:22 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 04:59:53 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long long int	ft_z(struct stat *allstats, char *path, t_finfo *file_st,
						t_lenmax *max)
{
	char	*all_path;
	int		len;

	all_path = ft_strjoin(path, "/");
	all_path = ft_strjoin_free(all_path, file_st->name, 1);
	if ((len = ft_strlen(file_st->name)) > max->lenmax_name)
		max->lenmax_name = len;
	file_st->link = ft_handle_link(all_path);
	if ((ft_call_stat(allstats, max->flags, all_path)) == -1)
		return (-1);
	if ((len = ft_ilen(allstats->st_nlink)) > max->lenmax_link)
		max->lenmax_link = len;
	file_st->n_link = allstats->st_nlink;
	ft_file_time(allstats, file_st);
	ft_handle_mode(allstats, file_st);
	ft_file_size(allstats, file_st, max);
	ft_find_uid_gid(allstats, file_st, max);
	ft_memdel((void **)&all_path);
	return (allstats->st_blocks);
}

t_btree			*ft_take_infofile(char *path, DIR *dir, t_list **b_list,
									t_lenmax *max)
{
	struct dirent	*fileinfo;
	struct stat		allstats;
	t_finfo			file_st;
	t_btree			*root;
	t_list			*elem;

	root = NULL;
	while ((fileinfo = readdir(dir)))
	{
		ft_bzero(&file_st, sizeof(t_finfo));
		file_st.name = ft_strdup(fileinfo->d_name);
		if ((max->total_size += ft_z(&allstats, path, &file_st, max)) != -1)
		{
			if (file_st.mode[0] == 'd' && ft_strofpoint(file_st.name) == -1)
			{
				if (max->flags & MIN_A || file_st.name[0] != '.')
				{
					elem = ft_lstnew(file_st.name, ft_strlen(file_st.name) + 1);
					ft_lstaddback(b_list, elem);
				}
			}
			root = select_inser(root, &file_st, max);
		}
	}
	return (root);
}
