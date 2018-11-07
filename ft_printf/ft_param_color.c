/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:09:39 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/14 22:24:12 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_howc(const char *format)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (format[i] && format[i] != '}' && format[i] != ',')
	{
		i++;
		nb++;
	}
	return (nb);
}

static const t_color g_colors[] = {
	{"black", '0'}, {"red", '1'}, {"green", '2'}, {"yellow", '3'},
	{"blue", '4'}, {"magenta", '5'}, {"cyan", '6'}, {"white", '7'}
};

static const size_t g_colors_size = sizeof(g_colors) / sizeof(t_color);

char	ft_what_color(const char *format)
{
	int		nb;
	size_t	i;

	nb = ft_howc(format);
	i = 0;
	while (i < g_colors_size)
	{
		if (!(ft_strncmp(format, g_colors[i].name, nb)))
			return (g_colors[i].code);
		++i;
	}
	return ('7');
}

void	ft_buffer_color(char *code_color, t_printf *elem)
{
	int	res;

	res = BUFF_SIZE - elem->i_buff;
	if (res < (int)ft_strlen(code_color))
	{
		write(1, elem->buff, elem->i_buff);
		ft_bzero(elem->buff, BUFF_SIZE);
		elem->ret += elem->i_buff;
		elem->i_buff = 0;
	}
	ft_strcpy(&elem->buff[elem->i_buff], code_color);
	elem->i_buff += ft_strlen(code_color);
}

char	*ft_codecolor(char *code_color, char color, char sharp)
{
	*code_color = color;
	code_color++;
	*code_color = sharp;
	code_color++;
	return (code_color);
}

void	ft_param_color(t_printf *elem, const char *format)
{
	char	*back_color;
	char	*code_color;
	char	*tmp;

	(!(code_color = ft_memalloc(14))) ? exit(1) : 0;
	tmp = code_color;
	ft_strcpy(code_color, "\e[");
	code_color += 2;
	if (elem->flags & MORE)
		code_color = ft_codecolor(code_color, '7', ';');
	if (elem->flags & ZERO)
		code_color = ft_codecolor(code_color, '4', ';');
	if (elem->flags & SHARP)
		code_color = ft_codecolor(code_color, '1', ';');
	code_color = ft_codecolor(code_color, '3', ft_what_color(format));
	if ((back_color = ft_strcchr(format, ',', '}')))
	{
		*code_color = ';';
		code_color++;
		code_color = ft_codecolor(code_color, '4', ft_what_color(++back_color));
	}
	*code_color = 'm';
	ft_buffer_color(tmp, elem);
	ft_memdel((void **)&tmp);
}
