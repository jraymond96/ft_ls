/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:35:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/27 15:03:14 by jraymond         ###   ########.fr       */
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
# include <stdio.h> /* A ENLEVER */

/*
**-----------------------------------STRUCTS------------------------------------
*/

typedef struct			s_fileinfo
{
	char				*name;
	char				*n_id_user;
	char				*n_id_group;
	char				mode[11];
	char				type;
	char				timeday[13];
	time_t				time_u; /*flags u (st_atime)*/
	time_t				time_n;
	time_t				time_c; /*flags c (st_ctime)*/
	int					size;
}						t_finfo;

typedef struct			s_binary_tree
{
	void				*ptrdata;
	size_t				data_size;
	struct	s_btree		*parent;
	struct	s_btree		*left;
	struct	s_btree		*right;
}						t_btree;

typedef struct			s_test
{
	char				*name;
	int					nb;
}						t_test;

/*
**--------------------------------BTREE-FONCTIONS-------------------------------
*/

t_btree					*ft_btreeinser_ascii(t_btree *root, void *data,
						size_t size_data);
void					ft_print_tree(t_btree *root);

/*
**----------------------------------FONCTIONS-----------------------------------
*/

void			ft_handle_mode(struct stat *allstats, t_finfo *file_s);
void			ft_file_size(struct stat *allstats, t_finfo *file_s);
void			ft_file_time(struct stat *allstats, t_finfo *file_st);
void			ft_find_uid_gid(struct stat *allstats, t_finfo *file_st);

# endif
