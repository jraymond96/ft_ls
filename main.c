/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:37 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/29 12:30:24 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"
#include <time.h>

int		ft_error(void)
{
	ft_putstr("error1\n");
	return (0);
}

int		ft_recover_infofile(struct stat *allstats, char *path, t_finfo *file_st)
{
	char	*all_path;

	all_path = ft_strjoin(path, "/");
	all_path = ft_strjoin_free(all_path, file_st->name, 1);
	lstat(all_path, allstats);
	ft_file_time(allstats, file_st);
	ft_handle_mode(allstats, file_st);
	ft_file_size(allstats, file_st);
	ft_find_uid_gid(allstats, file_st);
	ft_memdel((void **)&all_path);
	return (0);
}

t_btree	*ft_take_files_infos(char *path, DIR *dir, t_list **b_list)
{
	struct dirent 	*fileinfo;
	struct stat		 allstats;
	t_finfo			*file_st;
	t_btree			*root;
	t_list			*elem;
	
	root = NULL;
	while ((fileinfo = readdir(dir)))
	{
		file_st = ft_memalloc(sizeof(t_finfo));
		file_st->name = ft_strdup(fileinfo->d_name);
		ft_recover_infofile(&allstats, path, file_st);
		if (file_st->mode[0] == 'd' && file_st->name[0] != '.')
		{
			//ft_putstr("name :");
			//ft_putendl(file_st->name);
			ft_putnbr(ft_strlen(file_st->name));
			elem = ft_lstnew(file_st->name, ft_strlen(file_st->name));
			ft_putstr("name :");
			ft_putnbr(ft_strlen(elem->content));
			ft_putendl(elem->content);
			ft_lstaddback(b_list, elem);
		}
		root = ft_btreeinser_ascii(root, (t_finfo *)file_st, sizeof(t_finfo));
	}
	return (root);
}

int		ft_recur_solve(char *path, DIR *dir)
{
	t_btree			*root;
	t_list			*b_list;
	t_list			*elem;
	char			*all_path;

	b_list = NULL;
	ft_putendl(path);
	root = ft_take_files_infos(path, dir, &b_list);
	elem = b_list;
	all_path = ft_strjoin(path, "/");
	ft_putendl(all_path);
	ft_print_tree(root);
	while (elem)
	{
		path = all_path;
		ft_putendl(elem->content);
		all_path = ft_strjoin(all_path, elem->content);
		ft_putstr("zzzzzzzzzzzz**************zzzzzzzzzzzz\n");
		ft_recur_solve(all_path, opendir(all_path));
		ft_putstr("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n");
		ft_memdel((void **)&all_path);
		all_path = path;
		elem = elem->next;
	}
	/*
	 * penser a free root et b_list
	 * */
	ft_memdel((void **)&all_path);
	return (0);
}

int		main(int argc, char **argv)
{
	DIR				*dir;
	char			*path;
	
	if (argc != 2)
	{
		if (!(dir = opendir("./")))
			return (ft_error());
		path = ft_strdup(".");
	}
	else
	{
		if (!(dir = opendir(argv[1])))
			return (ft_error());
		path = ft_strdup(argv[1]);
	}
	ft_recur_solve(path, dir);
	ft_memdel((void **)&path);
	closedir(dir);
	return (0);
}
	
/* 
** printf("n_id_user : %s\n", file_st.n_id_user);
** printf("n_id_group : %s\n", file_st.n_id_group);
** printf("time : %s\n", file_st.timeday);
** printf("mode : %s\n", file_st.mode);
** printf("size : %d\n", file_st.size);
*/
