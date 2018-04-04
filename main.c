/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:37 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/04 15:07:30 by jraymond         ###   ########.fr       */
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

int		ft_z(struct stat *allstats, char *path, t_finfo *file_st, t_lenmax *max)
{
	char	*all_path;
	int		len;

	all_path = ft_strjoin(path, "/");
	all_path = ft_strjoin_free(all_path, file_st->name, 1);
	file_st->link = ft_handle_link(all_path);
	lstat(all_path, allstats);
	if ((len = ft_ilen(allstats->st_nlink)) > max->lenmax_link)
		max->lenmax_link = len;
	file_st->n_link = allstats->st_nlink;
	ft_file_time(allstats, file_st);
	ft_handle_mode(allstats, file_st);
	ft_file_size(allstats, file_st, max);
	ft_find_uid_gid(allstats, file_st, max);
	ft_memdel((void **)&all_path);
	return (0);
}

t_list	*ft_lst_sort(t_list *b_list)
{
	t_list	*elem;
	t_list	*tmp;
	t_list	*lat;
	t_list	*parent;

	elem = b_list;
	if (b_list == NULL)
		return (NULL);
	parent = NULL;
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
				parent->next = lat;
			}
			elem = b_list;
		}
		else
		{
			parent = elem;
			elem = elem->next;
		}
	}
	return (b_list);
}

t_btree	*ft_take_infofile(char *path, DIR *dir, t_list **b_list, t_lenmax *max)
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
		ft_z(&allstats, path, &file_st, max);
		if (file_st.mode[0] == 'd' && file_st.name[0] != '.')
		{
			elem = ft_lstnew(file_st.name, (ft_strlen(file_st.name) + 1));
			ft_lstaddback(b_list, elem);
		}
		root = ft_btreeinser_ascii(root, &file_st, sizeof(t_finfo));
	}
	b_list = NULL;
	return (root);
}

void	ft_free_all(t_list **list, t_btree **root, DIR *dir, char **path)
{
	void	*ptr_tl;
	void	*ptr_tbt;

	ptr_tl = del;
	ptr_tbt = btdel;
	ft_lstdel(list, ptr_tl);
	ft_btreedel(root, ptr_tbt);
	ft_memdel((void **)path);
	closedir(dir);
}

int		ft_recur_solve(char *path, DIR *dir)
{
	t_btree			*root;
	t_list			*b_list;
	t_list			*elem;
	t_lenmax		lenmax;
	char			*all_path;

	b_list = NULL;
	ft_bzero(&lenmax, sizeof(t_lenmax));
	root = ft_take_infofile(path, dir, &b_list, &lenmax);
	b_list = ft_lst_sort(b_list);
	elem = b_list;
	all_path = ft_strjoin(path, "/");
	ft_print_tree(root, &lenmax);
	/*
	while (elem)
	{
		path = all_path;
		all_path = ft_strjoin(all_path, elem->content);
		ft_recur_solve(all_path, opendir(all_path));
		ft_memdel((void **)&all_path);
		all_path = path;
		elem = elem->next;
	}*/
	ft_free_all(&b_list, &root, dir, &all_path);
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
	return (0);
}
