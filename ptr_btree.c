/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_btree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:09:18 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/13 05:01:58 by jraymond         ###   ########.fr       */
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
