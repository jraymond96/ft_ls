/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:37 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 04:54:55 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	ft_call_allfile(t_btree *root, int flags, t_btree *end, t_recur *rec)
{
	DIR *dir;

	if (root->left && !(flags & MIN_R))
		ft_call_allfile(root->left, flags, end, rec);
	else if (root->right && flags & MIN_R)
		ft_call_allfile(root->right, flags, end, rec);
	dir = opendir((const char *)root->ptrdata);
	if (!dir)
		ft_error(root->ptrdata, rec->nb_arg);
	else
		ft_recur_solve(root->ptrdata, dir, flags, rec);
	if (root != end)
		ft_putchar('\n');
	if (root->right)
		ft_call_allfile(root->right, flags, end, rec);
	else if (root->left && flags & MIN_R)
		ft_call_allfile(root->left, flags, end, rec);
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

void	if_param(t_btree *param, int argc, t_recur *rec)
{
	if (!param)
		return ;
	rec->nb_arg = ft_how_dir(param, -1);
	if (param->left)
	{
		ft_call_file(param->left, argc);
		if (param->right)
			ft_putchar('\n');
	}
	if (param->right)
		ft_call_allfile(param->right, argc, ft_btreeend(param, 1), rec);
}

int		main(int argc, char **argv)
{
	DIR				*dir;
	char			*path;
	char			*opt;
	t_recur			rec;
	t_btree			*param;

	opt = NULL;
	if ((argc = ft_option_management((const char **)argv, &opt)) == -1)
		return (0);
	ft_bzero(&rec, sizeof(t_recur));
	param = ft_sorting_param((char const **)argv, argc);
	if (!param && ft_how_arg(argv) == 0)
	{
		if (!(dir = opendir("./")))
			ft_error("./", 0);
		path = ft_strdup(".");
		ft_recur_solve(path, dir, argc, &rec);
		ft_memdel((void **)&path);
	}
	if_param(param, argc, &rec);
	ft_free(&param, &opt);
	return (0);
}
