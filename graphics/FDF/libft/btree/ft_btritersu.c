/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btritersu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:31:13 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 12:31:25 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
