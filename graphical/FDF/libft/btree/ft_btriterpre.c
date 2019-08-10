/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btriterpre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:31:11 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 12:31:25 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
