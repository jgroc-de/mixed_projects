#include "libft.h"

int	ft_btrinsert(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*node;
	t_btree	*tmp;
	t_btree	*save;

	if (!(node = ft_btrnew(item)))
		return (0);
	tmp = *root;
	if (tmp)
	{
		while (tmp)
		{
			save = tmp;
			if (cmpf(tmp->left->item, item) > 0)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		if (cmpf(save->item, item) > 0)
			save->left = node;
		else
			save->right = node;
	}
	else
		*root = node;
	return (1);
}
