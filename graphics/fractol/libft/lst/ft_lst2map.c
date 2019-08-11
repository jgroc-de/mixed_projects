/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:09:50 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 19:35:11 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_lst2map(t_list2 *lst2, t_list2 *(*f)(t_list2 *elem))
{
	t_list2	*copy;
	t_list2	*save;
	t_list2	*tmp;

	if (!(copy = ft_lst2new(NULL, 0)))
		return (NULL);
	save = copy;
	while (lst2)
	{
		tmp = (*f)(lst2);
		copy->content = tmp->content;
		copy->content_size = tmp->content_size;
		lst2 = lst2->next;
		if (lst2)
		{
			if (!(copy->next = ft_lst2new(NULL, 0)))
				return (NULL);
			copy->next->prev = copy;
			copy = copy->next;
		}
	}
	return (save);
}
