/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:17:45 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 14:38:40 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_lst2pop(t_list2 *search, t_list2 *list2)
{
	t_list2	*node;
	t_list2	*save;

	list2->prev = NULL;
	if (list2 == search)
		list2 = list2->next;
	else
	{
		node = list2;
		save = list2;
		while (node && node != search)
		{
			save = node;
			node = node->next;
		}
		if (node)
		{
			save->next = node->next;
			node->next->prev = save;
		}
	}
	search->next = NULL;
	search->prev = NULL;
	return (search);
}
