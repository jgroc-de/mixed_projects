#include "libft.h"

t_btree *ft_btrnew(void *item)
{
	t_btree	*node;

	if ((node = (t_btree*)malloc(sizeof(t_btree))))
	{
		node->item = item;
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}
