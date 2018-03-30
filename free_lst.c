/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:11:39 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/30 11:49:17 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"

void	ft_del(void *elem, size_t content_size)
{
	content_size = 1;
	free(elem);
}

t_list	*test(char **argv)
{
	int		i;
	t_list	*elem;
	t_list	*b_lst;
	
	i = 0;
	elem = NULL;
	b_lst = NULL;
	while (argv[++i])
	{
		elem = ft_lstnew((char const *)argv[i], ft_strlen(argv[i]));
		ft_lstaddback(&b_lst, elem);
	}
	return (b_lst);
}

int main(int argc, char **argv)
{
	t_list	*b_lst;
	t_list	*elem;
	void	*ptr_del;

	argc = 1;
	ptr_del = &(ft_del);
	b_lst = test(argv);
	elem = b_lst;
	while (elem)
	{
		ft_putstr((char *)elem->content);
		ft_putstr("   ");
		elem = elem->next;
	}
	ft_lstdel(&b_lst, ptr_del);
	return (0);
}
