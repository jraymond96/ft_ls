/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:37 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/04 19:11:52 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"
#include <time.h>
#include <locale.h>
#include <errno.h>
#include "./ft_printf/ft_printf.h"

char	*tname_file(char *str)
{
	char	*tmp;
	while ((str = ft_strchr(str, '/')))
	{
		str++;
		tmp = str;
	}
	return(tmp);
}

int		ft_error(char *path)
{
	ft_printf("%s:\nls: %s: %s\n", path, tname_file(path), strerror(errno));
	return (0);
}

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
		return(-1);
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
		if ((max->total_size += ft_z(&allstats, path, &file_st, max)) != -1)
		{
			if (file_st.mode[0] == 'd' && ft_strofpoint(file_st.name) == -1)
			{
				if (max->flags & MIN_A || file_st.name[0] != '.')
				{
					elem = ft_lstnew(file_st.name, (ft_strlen(file_st.name) + 1));
					ft_lstaddback(b_list, elem);
				}
			}
			if (max->flags & MIN_T)
				root = ft_btreeinser_int(root, &file_st, sizeof(t_finfo));
			else
				root = ft_btreeinser_ascii(root, &file_st, sizeof(t_finfo));
		}
	}
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

int		ft_recur_solve(char *path, DIR *dir, int flags, int nb_arg)
{
	t_btree			*root;
	t_list			*b_list;
	t_list			*elem;
	t_lenmax		lenmax;
	char			*all_path;

	b_list = NULL;
	if (!dir)
		return (ft_error(path));
	ft_bzero(&lenmax, sizeof(t_lenmax));
	lenmax.flags = flags;
	ft_getinf_term(&lenmax);
	root = ft_take_infofile(path, dir, &b_list, &lenmax);
	b_list = ft_lst_sort(b_list);
	lenmax.path = path;
	if (flags & MIN_R)
		b_list = ft_lstrev(b_list);
	elem = b_list;
	all_path = ft_strjoin(path, "/");
	ft_print_tree(root, &lenmax, nb_arg);
	if (flags & MAX_R)
	{	
		while (elem)
		{
			ft_putchar('\n');
			path = all_path;
			all_path = ft_strjoin(all_path, elem->content);
			ft_recur_solve(all_path, opendir(all_path), flags, nb_arg);
			ft_memdel((void **)&all_path);
			all_path = path;
			elem = elem->next;
		}
	}
	ft_free_all(&b_list, &root, dir, &all_path);
	return (0);
}

void	ft_call_allfile(t_btree *root, int flags, t_btree *end, int nb_arg)
{
	DIR *dir;

	if (root->left && !(flags & MIN_R))
		ft_call_allfile(root->left, flags, end, nb_arg);
	else if (root->right && flags & MIN_R)
		ft_call_allfile(root->right, flags, end, nb_arg);
	if (!(dir = opendir((const char *)root->ptrdata)))
		ft_error(root->ptrdata);
	ft_recur_solve(root->ptrdata, dir, flags, nb_arg);
	if (root != end)
		ft_putchar('\n');
	if (root->right)
		ft_call_allfile(root->right, flags, end, nb_arg);
	else if (root->left && flags & MIN_R)
		ft_call_allfile(root->left, flags, end, nb_arg);

}

void	ft_free(t_btree **root, char **str)
{
	void *ptr;

	ptr = btdelbis;
	if (*root)
		ft_btreedel(root, ptr);
	if (str)
		ft_memdel((void **)str);
}

int		main(int argc, char **argv)
{
	DIR				*dir;
	char			*path;
	char			*opt;
	int				flags;
	t_btree			*param;

	(void)argc;
	opt = NULL;
	if ((flags = ft_option_management((const char **)argv, &opt)) == -1)
		return (0);
	param = ft_sorting_param((char const **)argv, flags);
	if (!param && ft_how_arg(argv) == 0)
	{
		if (!(dir = opendir("./")))
			ft_error("./");
		path = ft_strdup(".");
		ft_recur_solve(path, dir, flags, 0);
		ft_memdel((void **)&path);
	}
	else if (param)
	{
		if (param->left)
		{
			ft_call_file(param->left, flags);
			if (param->right)
				ft_putchar('\n');
		}
		if (param->right)
			ft_call_allfile(param->right, flags, ft_btreeend(param, 1), ft_how_dir(param, -1));
	}
	ft_free(&param, &opt);
	return (0);
}
