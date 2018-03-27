/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 08:46:39 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/27 11:30:48 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "lib/libft.h"

t_btree	*ft_btreeinser_ascii(t_btree *root, void *data, size_t size_data);

void	ft_print_tree(t_btree *root)
{
	t_btree	*elem;

	elem = root;
	if (elem->left)
		ft_print_tree((t_btree *)elem->left);
	ft_putstr(((t_test *)elem->ptrdata)->name);
	ft_putchar('\n');
	if (elem->right)
		ft_print_tree((t_btree *)elem->right);
}

int	main(int argc, char **argv)
{
	t_test	a;
	t_btree	*root;
	int	i;
	
	i = 1;
	root = NULL;
	if (argc < 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	while (argv[i])
	{
		a.name = ft_strdup(argv[i]);
		a.nb = i++;
		root = ft_btreeinser_ascii(root, &a, sizeof(t_test));
		ft_bzero(&a, sizeof(t_test));
	}
	ft_print_tree(root);
	exit (0);
}
