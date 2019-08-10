/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:31:02 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 12:31:25 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
