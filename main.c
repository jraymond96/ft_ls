/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 01:37:54 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/03 18:21:03 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	call_recur(t_btree *root, int flags, t_recur *rec, t_btree *end)
{
	if (root->left && !(flags & MIN_R))
		call_recur(root->left, flags, rec, end);
	else if (root->right && flags & MIN_R)
		call_recur(root->right, flags, rec, end);
	ft_recur_solve(INFP->name, opendir(INFP->name), flags, rec);
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
	t_btree	*first;

	if (!param)
		return ;
	ft_bzero(&rec, sizeof(t_recur));
	if (param->file)
	{
		first = ft_btreeend(param->dir, -1);
		ft_printf("%s:\n", ((t_infp *)first->ptrdata)->name);
		rec.nb_arg = 1;
	}
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
	}
	ft_memdel((void **)param);
}

int		main(int argc, char **argv)
{
	int		ret;
	t_param	*param;
	t_recur	rec;

	ret = ft_get_opt(argv, &argc, astobin);
	param = NULL;
	ft_bzero(&rec, sizeof(t_recur));
	if (ret < 0)
		return (0);
	if (ret > 0)
	{
		param = get_param(&argv[ret], argc);
		if (param->file)
		{
			call_files(param->file, argc);
			param->dir ? ft_putchar('\n') : NULL;
		}
		if (param->dir)
			call_folder(param, argc);
	}
	else
		ft_recur_solve("./", opendir("./"), argc, &rec);
	free_param(&param);
	return (0);
}
