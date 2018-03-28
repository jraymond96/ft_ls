/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:37 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/28 10:03:15 by jraymond         ###   ########.fr       */
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

int		ft_recur_solve(char *path, DIR *dir)
{
	struct dirent 	*fileinfo;
	struct stat		 allstats;
	t_finfo			file_st;
	t_btree			*root;
	t_list			*b_list;
	t_list			*elem;
	int				i;

	root = NULL;
	elem = NULL;
	b_list = NULL;
	while ((fileinfo = readdir(dir)))
	{
		ft_bzero(&file_st, sizeof(t_finfo));
		file_st.name = fileinfo->d_name;
		ft_recover_infofile(&allstats, path, &file_st);
		if (file_st.mode[0] == 'd')
		{
			elem = ft_lstnew(file_st.name, sizeof(char *));
			ft_lstaddback(&b_list, elem);
		}
		root = ft_btreeinser_ascii(root, (t_finfo *)&file_st, sizeof(t_finfo));
	}
	i = 0;
	elem = b_list;
	while (b_list)
	{
		ft_putstr(b_list->content);
		ft_putchar('\n');
		b_list = b_list->next;
	}
	ft_print_tree(root);
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
