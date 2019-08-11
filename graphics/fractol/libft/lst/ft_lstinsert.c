/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:18:33 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 14:28:35 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstinsert(t_list *list, t_list *element)
{
	t_list	*tmp;

	tmp = list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		element->next = NULL;
		tmp->next = element;
	}
	else
		list = element;
	return (list);
}
