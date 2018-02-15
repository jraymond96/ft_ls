/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:37 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/15 22:50:08 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

char	ft_r_w_x(int i)
{
		if (i == 8 || i == 5 || i == 2)
			return ('r');
		else if (i == 7 || i == 4 || i == 1)
			return ('w');
		else
			return ('x');
}

void	ft_handle_mode(struct stat *more_stats, t_finfo *file_s)
{
	int	i;
	int	x;

	i = 8;
	x = 0;
	file_s->mode[x++] = ;
	while (i != -1)
	{
		if (more_stats->st_mode & (1 << i))
			file_s->mode[x++] = ft_r_w_x(i);
		else
			file_s->mode[x++] = '-';
		i--;
	}
}

int		main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent 	*fileinfo;
	struct stat		 more_st;
	t_finfo			file_st;
	
	if (argc != 2)
		return (0);
	dir = opendir(argv[1]);
	fileinfo = readdir(dir);
	ft_bzero(&file_st, sizeof(t_finfo));
	lstat("./test/d", &more_st);
	printf("NAME : %s", )
	ft_handle_mode(&more_st, &file_st);
	printf("mode : %s", file_st.mode);
	closedir(dir);
}
