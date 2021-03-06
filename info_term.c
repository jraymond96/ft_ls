/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:06:09 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 07:19:10 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_getinf_term(t_lenmax *max)
{
	struct winsize argp;

	if ((ioctl(0, TIOCGWINSZ, &argp)) == -1)
		ft_dprintf(2, "%s\n", strerror(errno));
	else
		max->nb_col = argp.ws_col;
	return (0);
}
