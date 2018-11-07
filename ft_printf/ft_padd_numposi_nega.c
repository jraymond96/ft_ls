/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padd_numposi_nega.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:05:47 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 18:59:30 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_neg_no_minus(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{
	char	sp;
	char	zero;
	char	more;

	sp = ' ';
	more = '+';
	zero = '0';
	if (!(elem->flags & ZERO))
	{
		ft_handle_overflow(elem, &sp, nbca->width, 1);
		ft_handle_overflow(elem, &numb[0], 1, 1);
	}
	else
	{
		ft_handle_overflow(elem, &numb[0], 1, 1);
		ft_handle_overflow(elem, &zero, nbca->width, 1);
	}
	numb++;
	ft_handle_overflow(elem, &zero, nbca->preci, 1);
	ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
}

void	ft_posi_no_minus(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{
	char	sp;
	char	zero;
	char	more;

	sp = ' ';
	more = '+';
	zero = '0';
	if (!(elem->flags & ZERO))
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	else
		ft_handle_overflow(elem, &zero, nbca->width, 1);
	if (elem->flags & MORE)
		ft_handle_overflow(elem, &more, 1, 1);
	ft_handle_overflow(elem, &zero, nbca->preci, 1);
	ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
}
