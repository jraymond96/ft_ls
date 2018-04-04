/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:50:29 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/04 13:36:49 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "lib/libft.h"

void	ft_file_size(struct stat *allstats, t_finfo *file_st, t_lenmax *max)
{
	int	len;

	file_st->size = allstats->st_size;
	if ((len = ft_ilen(file_st->size)) > max->lenmax_oct)
		max->lenmax_oct = len;
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
		return ('B');
	else if (S_ISBLK(allstats->st_mode))
		return ('c');
	else if (S_ISFIFO(allstats->st_mode))
		return ('P');
	else
		return ('S');
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
	{
		file_s->mode[x++] = allstats->st_mode & (1 << i) ? res[(x - 1)] : '-';
	}
}
