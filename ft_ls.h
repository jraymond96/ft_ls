/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:35:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/17 22:39:09 by jraymond         ###   ########.fr       */
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
# include <stdio.h> /* A ENLEVER */

/*
**-----------------------------------STRUCTS------------------------------------
*/

typedef struct	s_fileinfo
{
	char	*name;
	char	mode[11];
	char	type;
	char	timeday[13];
	time_t	time_u; /*flags u (st_atime)*/
	time_t	time_n;
	time_t	time_c; /*flags c (st_ctime)*/
	int		size;
}				t_finfo;

/*
**----------------------------------FONCTIONS-----------------------------------
*/

void			ft_handle_mode(struct stat *allstats, t_finfo *file_s);
void			ft_file_size(struct stat *allstats, t_finfo *file_s);
void			ft_file_time(struct stat *allstats, t_finfo *file_st);

# endif
