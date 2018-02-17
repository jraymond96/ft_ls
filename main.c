/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:37 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/17 23:13:00 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"
#include <time.h>

int		ft_error(void)
{
	ft_putstr("error1\n");
	return (0);
}

int		main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent 	*fileinfo;
	struct stat		 allstats;
	t_finfo			file_st;
	
	if (argc != 2)
		return (ft_error());
	if (!(dir = opendir(argv[1])))
		return (ft_error());
	fileinfo = readdir(dir);
	ft_bzero(&file_st, sizeof(t_finfo));
	lstat("./test/test0.c", &allstats);
	ft_file_time(&allstats, &file_st);
	printf("time : %s\n", file_st.timeday);
	ft_handle_mode(&allstats, &file_st);
	printf("mode : %s", file_st.mode);
	ft_file_size(&allstats, &file_st);
	closedir(dir);
}
