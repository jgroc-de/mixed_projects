/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:31:18 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 12:32:07 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btrsearch(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	t_btree	*out;

	if (root)
	{
		if (cmpf(root->item, data_ref))
		{
			return (root);
		}
		if ((out = ft_btrsearch(root->left, data_ref, cmpf)))
			return (out);
		if ((out = ft_btrsearch(root->right, data_ref, cmpf)))
			return (out);
	}
	return (NULL);
}
