/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:35:27 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/30 19:33:45 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unicode_to_str(wchar_t unicode, char *str)
{
	if ((unicode >= 0 && unicode <= 127) || (unicode > 127 && unicode < 255 &&
			MB_CUR_MAX == 1))
		str[0] = unicode;
	else if (unicode >= 128 && unicode <= 2047)
	{
		str[0] = (unicode >> 6) | 192;
		str[1] = (unicode & 63) | (1 << 7);
	}
	else if ((unicode >= 2048 && unicode <= 55295) ||
				(unicode >= 57344 && unicode <= 65535))
	{
		str[0] = (unicode >> 12) | 224;
		str[1] = ((unicode >> 6) & 63) | (1 << 7);
		str[2] = (unicode & 63) | (1 << 7);
	}
	else
	{
		str[0] = (unicode >> 18) | 240;
		str[1] = ((unicode >> 12) & 63) | (1 << 7);
		str[2] = ((unicode >> 6) & 63) | (1 << 7);
		str[3] = (unicode & 63) | (1 << 7);
	}
}
