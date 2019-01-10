#include "libft.h"

/*
** parcours suffix d'un arbre binaire
*/

void	ft_btritersu(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		ft_btritersu(root->right, f);
		f(root->item);
		ft_btritersu(root->left, f);
	}
}
