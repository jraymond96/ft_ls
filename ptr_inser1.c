/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_inser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:38:00 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/02 21:39:21 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		inser_ascii(void *data1, void *data2)
{
	return (ft_strcmp(((t_finfo *)data1)->name, ((t_finfo *)data2)->name));
}

int		inser_time(void *data1, void *data2)
{
	int	res;

	if ((res = ((t_finfo *)data2)->time - ((t_finfo *)data1)->time) == 0)
		return (inser_ascii(data1, data2));
	else
		return (res);
}

int		inser_size(void *data1, void *data2)
{
	int	res;

	if ((res = ((t_finfo *)data2)->size - ((t_finfo *)data1)->size) == 0)
		return (inser_ascii(data1, data2));
	else
		return (res);
}
