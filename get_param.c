/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 03:31:01 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/02 21:41:34 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		*ptrcmp(int flags)
{
	void	*ptr[3];
	int		x;

	ptr[0] = p_inser_ascii;
	ptr[1] = p_inser_time;
	ptr[2] = p_inser_size;
	x = 0;
	if (flags & MIN_T)
		x = 1;
	return (ptr[x]);
}

void		*ptrcmp1(int flags)
{
	void	*ptr[3];
	int		x;

	ptr[0] = inser_ascii;
	ptr[1] = inser_time;
	ptr[2] = inser_size;
	x = 0;
	if (flags & MIN_T)
		x = 1;
	return (ptr[x]);
}

void		init_info(t_infp *info, struct stat *stats, char *argv)
{
	info->name = ft_strdup(argv);
	info->time = stats->st_mtime;
}

t_param		*get_param(char **argv, int flags)
{
	t_infp		info;
	t_param		*param;
	struct stat	stats;
	void		*ptr;

	ptr = ptrcmp(flags);
	param = ft_memalloc(sizeof(t_param));
	while (*argv)
	{
		if (call_lstat(&stats, *argv) != -1)
		{
			init_info(&info, &stats, *argv);
			if (S_ISDIR(stats.st_mode))
				param->dir = ft_btreeinser(param->dir, &info, sizeof(t_infp),
														ptr);
			else
				param->file = ft_btreeinser(param->file, &info, sizeof(t_infp),
											ptr);
		}
		argv++;
	}
	return (param);
}
