/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:50:29 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/15 02:58:09 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "sys/types.h"

void	ft_file_size(struct stat *allstats, t_finfo *file_st, t_lenmax *max)
{
	short	len;
	short	len1;
	short	res;

	if (file_st->size != -1)
	{
		file_st->size = allstats->st_size;
		if ((len = ft_ilen(file_st->size)) > max->lenmax_oct)
			max->lenmax_oct = len;
	}
	else
	{
		if ((len = ft_ilen(file_st->minor)) > max->lenmax_mino)
			max->lenmax_mino = len;
		if ((len1 = ft_ilen(file_st->major)) > max->lenmax_majo)
			max->lenmax_majo = len1;
	}
	if (max->lenmax_mino < (len1 = ft_ilen(file_st->size)))
		max->lenmax_mino = len1;
	res = max->lenmax_mino + max->lenmax_majo + 2;
	if (res > max->lenmax_oct && max->lenmax_majo)
		max->lenmax_oct = res;
}

char	ft_file_type(struct stat *allstats)
{
	if (S_ISREG(allstats->st_mode))
		return ('-');
	else if (S_ISDIR(allstats->st_mode))
		return ('d');
	else if (S_ISLNK(allstats->st_mode))
		return ('l');
	else if (S_ISCHR(allstats->st_mode))
		return ('c');
	else if (S_ISBLK(allstats->st_mode))
		return ('b');
	else if (S_ISFIFO(allstats->st_mode))
		return ('p');
	else
		return ('s');
}

void	is_exe(struct stat *allst, char *mode)
{
	if (S_ISUID & allst->st_mode)
	{
		if (!(S_IXUSR & allst->st_mode))
			mode[3] = 'S';
		else
			mode[3] = 's';
		if (!(S_IXGRP & allst->st_mode))
			mode[6] = 'S';
		else
			mode[6] = 's';
	}
	if (S_ISVTX & allst->st_mode)
	{
		if (!(S_IXOTH & allst->st_mode) || !(S_IROTH & allst->st_mode))
			mode[9] = 'T';
		else
			mode[9] = 't';
	}
}

void	ft_handle_mode(struct stat *allstats, t_finfo *file_s)
{
	int		i;
	int		x;
	char	res[10];

	i = 9;
	x = 0;
	ft_strcpy(res, "rwxrwxrwx");
	file_s->mode[x++] = ft_file_type(allstats);
	while (--i != -1)
		file_s->mode[x++] = allstats->st_mode & (1 << i) ? res[(x - 1)] : '-';
	is_exe(allstats, file_s->mode);
	if (file_s->mode[0] == 'b' || file_s->mode[0] == 'c')
	{
		file_s->major = major(allstats->st_rdev);
		file_s->minor = minor(allstats->st_rdev);
		file_s->size = -1;
	}
}
