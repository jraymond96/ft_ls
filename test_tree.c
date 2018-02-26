#include "ft_ls.h"
#include "lib/libft.h"

t_btree	*ft_btreeinser_ascii(t_btree *root, void *data, size_t size_data);

void	print_tree(t_btree *root)
{
	t_btree	*elem;
	int	right;

	right = 0;
	elem = root;
	while (elem->left)
	{
		elem = elem->left;
	}
}

int	main(int argc, char **argv)
{
	t_test	a;
	t_btree	*root;
	int	i;
	
	i = 1;
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
	}
	exit (0);
}
