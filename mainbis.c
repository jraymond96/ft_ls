/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 01:53:17 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/13 09:36:07 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print(void *ptrdata)
{
	ft_printf("apres : %s\n", ((t_infp *)ptrdata)->name);
}

void	call_recur(t_btree *root, int flags, t_recur *rec, t_btree *end)
{
	DIR		*dir;

	if (root->left && !(flags & MIN_R))
		call_recur(root->left, flags, rec, end);
	else if (root->right && flags & MIN_R)
		call_recur(root->right, flags, rec, end);
	dir = opendir(((t_infp *)root->ptrdata)->name);
	ft_recur_solve(((t_infp *)root->ptrdata)->name, dir, flags, rec);
	if (root != end)
		ft_putchar('\n');
	if (root->right && !(flags & MIN_R))
		call_recur(root->right, flags, rec, end);
	else if (root->left && flags & MIN_R)
		call_recur(root->left, flags, rec, end);
}

void	call_folder(t_param *param, int flags)
{
	t_recur	rec;

	if (!param)
		return ;
	ft_bzero(&rec, sizeof(t_recur));
	if (param->file)
		rec.nb_arg = 1;
	else
		rec.nb_arg = ft_btreelen(param->dir, &rec.nb_arg);
	call_recur(param->dir, flags, &rec, ft_btreeend(param->dir, 1));
}

int		main(int argc, char **argv)
{
	int		ret;
	void 	*ptr;
	t_param	*param;


	ptr = astobin;
	ret = ft_get_opt(argv, &argc, ptr);
	param = NULL;
	if (ret < 0)
		return (0);
	if (ret > 0)
	{
		ptr = print;
		param = get_param(&argv[ret], argc);
		if (param->file)
			call_files(param->file, argc);
		else
			ft_putendl("FILE : NULL");
		if (param->dir)
			call_folder(param, argc);
		else
			ft_putendl("DIR : NULL");
	}
	else
	{
		printf("{%d}\n", ret);
		printf("flags {%d}\n", argc);
		ft_putendl("lancer ls avec ./");
	}
	ptr = del_infp;
	if (param->dir)
		ft_btreedel(&param->dir, ptr);
	if (param->file)
		ft_btreedel(&param->file, ptr);
	if (param)
		ft_memdel((void **)&param);
	return (0);
}
