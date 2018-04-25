/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:35:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/25 11:45:28 by jraymond         ###   ########.fr       */
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
	int					lenmax_name;
	long long int		total_size;
	unsigned short		nb_row;
	unsigned short		nb_col;
	int					flags;
}						t_lenmax;

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
int				ft_recur_solve(char *path, DIR *dir, int flags);
void			del(void *elem, size_t content_size);
void			btdel(void *elem);
void			btdelbis(void *elem);
void			ft_print_tree(t_btree *root, t_lenmax *max);
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

# endif
