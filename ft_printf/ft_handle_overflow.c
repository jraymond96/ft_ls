/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:14:30 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/31 11:58:56 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nnn(t_overflow *ovflow, t_printf *elem, int nb, int spe)
{
	if (ovflow->flag == 1)
	{
		if (spe == 1)
			ft_memset(&elem->buff[elem->i_buff], *ovflow->data_b, ovflow->i);
		else if (spe == 2)
		{
			ft_strncat(&elem->buff[elem->i_buff], ovflow->data_b, ovflow->i);
			ovflow->data_b += ovflow->i;
		}
		nb -= ovflow->i;
		elem->i_buff += ovflow->i;
	}
	if (ovflow->flag == 2)
	{
		if (spe == 1)
			ft_memset(&elem->buff[elem->i_buff], *ovflow->data_b, nb);
		else if (spe == 2)
			ft_strncat(&elem->buff[elem->i_buff], ovflow->data_b, nb);
		elem->i_buff += nb;
		nb = 0;
	}
	return (nb);
}

void	ft_handle_overflow(t_printf *elem, void *data, int nb, int spe)
{
	t_overflow	ovflow;

	ft_bzero(&ovflow, sizeof(t_overflow));
	ovflow.data_b = (char *)data;
	while (nb)
	{
		ovflow.i = 0;
		if ((elem->i_buff + nb) > BUFF_SIZE &&
				(ovflow.i = BUFF_SIZE - elem->i_buff) == 0)
		{
			write(1, elem->buff, BUFF_SIZE);
			ft_bzero(elem->buff, BUFF_SIZE);
			elem->ret += elem->i_buff;
			elem->i_buff = 0;
		}
		else if ((elem->i_buff + nb) > BUFF_SIZE && (ovflow.flag = 1))
			nb = nnn(&ovflow, elem, nb, spe);
		else
		{
			ovflow.flag = 2;
			nb = nnn(&ovflow, elem, nb, spe);
		}
	}
}
