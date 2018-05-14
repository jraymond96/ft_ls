/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 03:31:01 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/14 04:10:43 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		*ptrcmp(int flags)
{
	void	*ptr[2];
	int		x;

	ptr[0] = p_inser_ascii;
	ptr[1] = p_inser_time;
	x = 0;
	if (flags & MIN_T)
		x = 1;
	return (ptr[x]);
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
			info.name = ft_strdup(*argv);
			info.time = stats.st_mtime;
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
