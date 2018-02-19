/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uid_gid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:27:02 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/19 17:49:57 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "ft_ls.h"

void	ft_find_uid_gid(struct stat *allstats, t_finfo *file_st)
{
	struct passwd	*id_user;
	struct group	*id_group;

	!(id_user = getpwuid(allstats->st_uid)) ? exit (1) : 0;
	!(id_group = getgrgid(allstats->st_gid)) ? exit (1) : 0;
	file_st->n_id_user = ft_strdup(id_user->pw_name);
	file_st->n_id_group = ft_strdup(id_group->gr_name);
}
