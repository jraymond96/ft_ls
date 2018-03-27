/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:37 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/27 12:23:41 by jraymond         ###   ########.fr       */
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

int		ft_recover_infofile(struct stat *allstats, char *path, t_finfo *file_st)
{
		path = ft_strjoin_free(path, "/", );
		lstat(path/file_st->name, &allstats);
		ft_file_time(allstats, file_st);
		ft_handle_mode(allstats, file_st);
		ft_file_size(allstats, file_st);
		ft_find_uid_gid(allstats, file_st);
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
	path = ft_strdup(argv[1]);
	while ((fileinfo = readdir(dir)))
	{
		ft_bzero(&file_st, sizeof(t_finfo));
		file_st.name = fileinfo->d_name;
		ft_recover_infofile(&allstats, path, &file_st);
	}
	closedir(dir);
	return (0);
}
	
/* 
** printf("n_id_user : %s\n", file_st.n_id_user);
** printf("n_id_group : %s\n", file_st.n_id_group);
** printf("time : %s\n", file_st.timeday);
** printf("mode : %s\n", file_st.mode);
** printf("size : %d\n", file_st.size);
*/
