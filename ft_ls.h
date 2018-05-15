/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:35:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/15 09:48:10 by jraymond         ###   ########.fr       */
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
# include "lib/libft.h"
# include "./ft_printf/ft_printf.h"
# define PATH ((t_finfo *)elem)
# define INFP ((t_infp *)root->ptrdata)

/*
**-----------------------------------STRUCTS------------------------------------
*/

typedef struct			s_mask
{
	char				flags;
	int					mask;
}						t_mask;

typedef struct			s_param
{
	t_btree				*file;
	t_btree				*dir;
}						t_param;

typedef	struct			s_info_param
{
	char				*name;
	size_t				time;
}						t_infp;

typedef struct			s_info_recur
{
	int					nb_arg;
	unsigned int		a : 1;
}						t_recur;

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
	t_recur				*rec;
}						t_lenmax;

typedef struct			s_fileinfo
{
	char				*name;
	char				*n_id_user;
	char				*n_id_group;
	char				*link;
	char				mode[11];
	char				timeday[13];
	int					n_link;
	unsigned int		n_perm : 1;
	int					minor;
	int					major;
	time_t				time_n;
	int					size;
	t_lenmax			*max;
}						t_finfo;

/*
**-------------------------------------MASK-------------------------------------
*/

# define MAX_R (1 << 0)
# define MIN_L (1 << 1)
# define MIN_A (1 << 2)
# define MIN_R (1 << 3)
# define MIN_T (1 << 4)
# define MIN_U (1 << 5)

/*
**----------------------------------FONCTIONS-----------------------------------
*/

void			ft_handle_mode(struct stat *allstats, t_finfo *file_s);
void			ft_file_size(struct stat *allstats, t_finfo *file_s,
								t_lenmax *max);
void			ft_file_time(struct stat *allstats, t_finfo *file_st,
								int flags);
void			ft_find_uid_gid(struct stat *allstats, t_finfo *file_st,
									t_lenmax *max);
long long int	ft_z(struct stat *allstats, char *path, t_finfo *file_st,
						t_lenmax *max);
char			*ft_handle_link(char *path);
int				ft_strofpoint(char *str);
int				ft_error(char *path, int nb_arg);
t_btree			*select_inser(t_btree *root, t_finfo *info, t_lenmax *max);
void			ft_print_tree(t_btree *root, t_lenmax *max, t_recur *rec);
t_btree			*ft_take_infofile(char *path, DIR *dir, t_btree **folder,
									t_lenmax *max);
int				ft_recur_solve(char *path, DIR *dir, int flags, t_recur *rec);
t_param			*get_param(char **argv, int flags);
void			*ptrcmp(int flags);
void			call_files(t_btree *root, int flags);
void			ft_free_all(t_btree **root, t_btree **folder, DIR *dir,
								t_lenmax *max);
int				call_lstat(struct stat *allstats, char *path);
int				call_llstat(struct stat *allstats, char *path);
char			*tname_file(char *str);
int				is_empty(t_btree *root, int i);
int				ft_getinf_term(t_lenmax *max);

/*
**-------------------------------------ptr_fonc_print--------------------------
*/

void			long_print(t_btree *elem, t_lenmax *max);
void			normal_print(t_btree *elem, t_lenmax *max, int len);
void			del(void *elem, size_t content_size);
void			btdel(void *elem);
void			btdelbis(void *elem);
int				lst_ncmp(t_list *elem);
int				lst_tcmp(t_list *elem);
int				inser_time(void *data1, void *data2);
int				inser_ascii(void *data1, void *data2);

int				p_inser_time(void *data1, void *data2);
int				p_inser_ascii(void *data1, void *data2);
void			print(void *ptrdata);
int				astobin(char *arg, int x, int y, int flags);
void			del_infp(void *ptrdata);
void			frefre(void *elem);
void			simpleprint(void *elem);
void			lprint(void *elem);

#endif
