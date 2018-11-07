/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 22:56:59 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 18:35:36 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_binary(t_printf *elem, long long binary, int size)
{
	int		i;
	char	bin[73];
	int		x;

	x = 0;
	ft_bzero(bin, 73);
	i = (size * 8 - 1);
	while (i >= 0)
	{
		if (!((i + 1) % 4))
			bin[x++] = '|';
		bin[x] = binary & BINARY ? '1' : '0';
		i--;
		x++;
	}
	bin[x] = '\n';
	ft_handle_overflow(elem, bin, ft_strlen(bin), 2);
	return (0);
}

int		ft_print_ubinary(t_printf *elem, unsigned long long binary, int size)
{
	int		i;
	char	bin[73];
	int		x;

	x = 0;
	ft_bzero(bin, 73);
	i = (size * 8 - 1);
	while (i >= 0)
	{
		if (!((i + 1) % 4))
			bin[x++] = '|';
		bin[x] = binary & BINARY ? '1' : '0';
		i--;
		x++;
	}
	bin[x] = '\n';
	ft_handle_overflow(elem, bin, ft_strlen(bin), 2);
	return (0);
}
