/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btriterin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:31:08 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 12:31:25 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
