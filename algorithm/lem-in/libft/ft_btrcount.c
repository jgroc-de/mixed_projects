#include "libft.h"

int	ft_btrcount(t_btree *root)
{
	int	i;

	i = 1;
	if (root)
	{
		i += ft_max(ft_btrcount(root->left), ft_btrcount(root->right));
	}
	if (!root)
		return (0);
	return (i);
}
