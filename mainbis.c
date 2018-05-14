/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 01:53:17 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/14 07:36:58 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	free_param(t_param **param)
{
	if (*param)
	{
		if ((*param)->dir)
			ft_btreedel(&(*param)->dir, del_infp);
		if ((*param)->file)
			ft_btreedel(&(*param)->file, del_infp);
		ft_memdel((void **)&param);
	}
}

int		main(int argc, char **argv)
{
	int		ret;
	void	*ptr;
	t_param	*param;
	t_recur	rec;

	ptr = astobin;
	ret = ft_get_opt(argv, &argc, ptr);
	param = NULL;
	ft_bzero(&rec, sizeof(t_recur));
	if (ret < 0)
		return (0);
	if (ret > 0)
	{
		param = get_param(&argv[ret], argc);
		if (param->file)
			call_files(param->file, argc);
		if (param->dir)
			call_folder(param, argc);
	}
	else
		ft_recur_solve("./", opendir("./"), argc, &rec);
	return (0);
}
