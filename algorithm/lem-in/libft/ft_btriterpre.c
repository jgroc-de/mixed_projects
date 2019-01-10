#include "libft.h"

/*
** parcours prefix d'un arbre binaire
*/

void	ft_btriterpre(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		ft_btriterpre(root->left, f);
		f(root->item);
		ft_btriterpre(root->right, f);
	}
}
