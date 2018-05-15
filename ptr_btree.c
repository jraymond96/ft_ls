/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_btree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:09:18 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/15 08:42:29 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		p_inser_ascii(void *data1, void *data2)
{
	return (ft_strcmp(((t_infp *)data1)->name, ((t_infp*)data2)->name));
}

int		p_inser_time(void *data1, void *data2)
{
	int	res;

	if ((res = ((t_infp *)data2)->time - ((t_infp *)data1)->time) == 0)
		return (inser_ascii(data1, data2));
	else
		return (res);
}

void	del_infp(void *ptrdata)
{
	ft_memdel((void **)&((t_infp *)ptrdata)->name);
	ft_memdel(&ptrdata);
}

void	lprint(void *elem)
{
	if (PATH->size != -1)
	{
		ft_printf("%s  %*d %-*s  %-*s   %*d %s %s",
		PATH->mode, PATH->max->lenmax_link, PATH->n_link,
		PATH->max->lenmax_u, PATH->n_id_user, PATH->max->lenmax_g,
		PATH->n_id_group, PATH->max->lenmax_oct, PATH->size, PATH->timeday,
		PATH->name);
	}
	else
	{
		ft_printf("%s  %*d %-*s  %-*s   %*d, %*d %s %s",
		PATH->mode, PATH->max->lenmax_link, PATH->n_link,
		PATH->max->lenmax_u, PATH->n_id_user, PATH->max->lenmax_g,
		PATH->n_id_group, PATH->max->lenmax_majo, PATH->major,
		PATH->max->lenmax_mino, PATH->minor, PATH->timeday, PATH->name);
	}
	if (PATH->link)
		ft_printf(" -> %s\n", PATH->link);
	else
		ft_putchar('\n');
}

void	simpleprint(void *elem)
{
	ft_putendl(PATH->name);
}
