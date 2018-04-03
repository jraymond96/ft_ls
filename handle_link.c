/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:18:44 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/03 20:27:13 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_handle_link(char *path)
{
	char	buf[512];
	char	*link;
	int		ret;

	ret = readlink(path, buf, 512);
	if (ret == -1)
		return (NULL);
	else
	{
		link = ft_memalloc(ret + 1);
		ft_strncpy(link, buf, ret);
	}
	return (link);
}
