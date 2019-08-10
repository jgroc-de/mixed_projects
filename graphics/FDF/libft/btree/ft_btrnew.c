/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:31:15 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 12:31:59 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btrnew(void *item)
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
