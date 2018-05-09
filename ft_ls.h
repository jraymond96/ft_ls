/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:35:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 06:42:19 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <locale.h>
# include <errno.h>
# include <time.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include "lib/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdio.h>
# define PATH ((t_finfo *)elem->ptrdata)
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
	int					minor;
	int					major;
	time_t				time_u; /*flags u (st_atime)*/
	time_t				time_n;
	time_t				time_c; /*flags c (st_ctime)*/
	int					size;
}						t_finfo;

typedef	struct			s_info_padding
{
	short				lenmax_u;
	short				lenmax_g;
	short				lenmax_oct;
	short				lenmax_link;
	short				lenmax_name;
	short				lenmax_mino;
	short				lenmax_majo;
	char				*path;
	long long int		total_size;
	unsigned short		nb_col;
	int					flags;
}						t_lenmax;

typedef struct			s_info_recur
{
	int					nb_arg;
	unsigned int		a : 1;
}						t_recur;

/*
**-------------------------------------MASK-------------------------------------
*/

# define MAX_R (1 << 0)
# define MIN_L (1 << 1)
# define MIN_A (1 << 2)
# define MIN_R (1 << 3)
# define MIN_T (1 << 4)

/*
**----------------------------------FONCTIONS-----------------------------------
*/

void			ft_handle_mode(struct stat *allstats, t_finfo *file_s);
void			ft_file_size(struct stat *allstats, t_finfo *file_s,
								t_lenmax *max);
void			ft_file_time(struct stat *allstats, t_finfo *file_st);
void			ft_find_uid_gid(struct stat *allstats, t_finfo *file_st,
									t_lenmax *max);
long long int	ft_z(struct stat *allstats, char *path, t_finfo *file_st,
						t_lenmax *max);
t_list			*ft_lst_sort(t_list *b_list);
t_btree			*ft_take_infofile(char *path, DIR *dir, t_list **b_list,
									t_lenmax *max);
int				ft_recur_solve(char *path, DIR *dir, int flags, t_recur *rec);
void			ft_print_tree(t_btree *root, t_lenmax *max, t_recur *rec);
char			*ft_handle_link(char *path);
int				ft_takeopt(char const **argv, const char *optstring,
								char **opt);
int				ft_erroropt(int i, char const ** argv);
int				ft_binaryflags(char *flags);
int				ft_option_management(char const **arg, char **flags);
t_btree			*ft_sorting_param(char const ** argv, int flags);
int				ft_strofpoint(char *str);
void			ft_call_file(t_btree *root, int flags);
int				ft_call_stat(struct stat *allstats, int flags, char *path);
int				ft_how_arg(char **argv);
int				ft_getinf_term(t_lenmax *max);
int				ft_how_dir(t_btree *root, int i);
int				is_empty(t_btree *root, int i);
t_btree			*select_inser(t_btree *root, t_finfo *info, t_lenmax *max);

void			ft_free_all(t_list **list, t_btree **root, DIR *dir,
								char **path);
int				ft_error(char *path, int nb_arg);
char			*tname_file(char *str);

/*
**-------------------------------------ptr_fonc_print--------------------------
*/

void			long_print(t_btree *elem, t_lenmax *max);
void			normal_print(t_btree *elem, t_lenmax *max);
void			del(void *elem, size_t content_size);
void			btdel(void *elem);
void			btdelbis(void *elem);

# endif
