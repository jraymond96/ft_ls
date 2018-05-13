/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 01:53:17 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/13 05:01:24 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print(void *ptrdata)
{
	ft_printf("apres : %s\n", ((t_infp *)ptrdata)->name);
}

void	print1(void *ptrdata)
{
	ft_printf("avant : %s\n", ((t_infp *)ptrdata)->name);
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
		if (param->dir)
			ft_putendl("DIR : *******");
		else
			ft_putendl("DIR : NULL");
		if (param->file)
			call_files(param->file, argc);
		else
			ft_putendl("FILE : NULL");
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
