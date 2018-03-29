/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:37 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/29 16:51:59 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"
#include <time.h>
#include <locale.h>

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

t_list	*ft_lst_sort(t_list *b_list)
{
	t_list	*elem;
	t_list	*tmp;
	t_list	*lat;

	elem = b_list;
	if (b_list == NULL)
		return (NULL);
	while (elem->next)
	{
		if (ft_strcmp(elem->content, elem->next->content) > 0)
		{
			if (elem == b_list)
			{
				b_list = elem->next;
				tmp = b_list->next;
				b_list->next = elem;
				elem->next = tmp;
			}
			else
			{	
				lat = elem->next;
				tmp = lat->next;
				lat->next = elem;
				elem->next = tmp;
			}
			elem = b_list;
		}
		else
			elem = elem->next;
	}
	return (b_list);
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
			elem = ft_lstnew(file_st->name, (ft_strlen(file_st->name) + 1));
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
	root = ft_take_files_infos(path, dir, &b_list);
	ft_putstr("---------------NO_SORT-----------\n");
	elem = b_list;
	while (elem)
	{
		ft_putendl((char *)elem->content);
		elem = elem->next;
	}
	elem = b_list;
	ft_putstr("----------------------------------\n");
	b_list = ft_lst_sort(b_list);
	elem = b_list;
	ft_putstr("------------------SORT------------\n");
	while (elem)
	{
		ft_putendl((char *)elem->content);
		elem = elem->next;
	}
	elem = b_list;
	ft_putstr("---------------------------------\n");
	all_path = ft_strjoin(path, "/");
	ft_print_tree(root);
	while (elem)
	{
		path = all_path;
		all_path = ft_strjoin(all_path, elem->content);
		ft_recur_solve(all_path, opendir(all_path));
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
