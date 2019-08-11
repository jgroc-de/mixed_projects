/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:18:33 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 14:28:35 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_lst2insert(t_list2 *list, t_list2 *element)
{
	t_list2	*tmp;

	tmp = list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		element->next = NULL;
		element->prev = tmp;
		tmp->next = element;
	}
	else
	{
		list = element;
		element->prev = NULL;
	}
	return (list);
}
