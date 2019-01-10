#include "libft.h"

/*
** parcours infix d'un arbre binaire
*/

void	ft_btriterin(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		f(root->item);
		ft_btriterin(root->left, f);
		ft_btriterin(root->right, f);
	}
}
