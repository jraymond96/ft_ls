/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_inser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:22:54 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/16 16:26:35 by jraymond         ###   ########.fr       */
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

int		p_inser_size(void *data1, void *data2)
{
	int	res;

	if ((res = ((t_infp *)data2)->size - ((t_infp *)data1)->size) == 0)
		return (inser_ascii(data1, data2));
	else
		return (res);
}
