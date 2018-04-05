/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:35:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/05 12:52:42 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include "lib/libft.h"
# include <stdio.h> /* A ENLEVER */

/*
**-----------------------------------STRUCTS------------------------------------
*/

typedef struct			s_fileinfo
{
	char				*name;
	char				*n_id_user;
	char				*n_id_group;
	char				*link;
	char				mode[11];
	char				type;
	char				timeday[13];
	int					n_link;
	time_t				time_u; /*flags u (st_atime)*/
	time_t				time_n;
	time_t				time_c; /*flags c (st_ctime)*/
	int					size;
}						t_finfo;

typedef	struct			s_info_padding
{
	int					lenmax_u;
	int					lenmax_g;
	int					lenmax_oct;
	int					lenmax_link;
	char				flags;
}						t_lenmax;

/*
**----------------------------------FONCTIONS-----------------------------------
*/

void			ft_handle_mode(struct stat *allstats, t_finfo *file_s);
void			ft_file_size(struct stat *allstats, t_finfo *file_s,
								t_lenmax *max);
void			ft_file_time(struct stat *allstats, t_finfo *file_st);
void			ft_find_uid_gid(struct stat *allstats, t_finfo *file_st,
									t_lenmax *max);
int				ft_z(struct stat *allstats, char *path, t_finfo *file_st,
						t_lenmax *max);
t_list			*ft_lst_sort(t_list *b_list);
t_btree			*ft_take_infofile(char *path, DIR *dir, t_list **b_list,
									t_lenmax *max);
int				ft_recur_solve(char *path, DIR *dir);
void			del(void *elem, size_t content_size);
void			btdel(void *elem);
void			ft_print_tree(t_btree *root, t_lenmax *max);
char			*ft_handle_link(char *path);
int				ft_takeopt(char const **argv, const char *optstring,
								char **opt);
int				ft_erroropt(int i, char const ** argv);

# endif
