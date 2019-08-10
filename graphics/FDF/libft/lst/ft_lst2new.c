/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:10:36 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 15:18:36 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_lst2new(void const *content, size_t content_size)
{
	t_list2	*list2;

	list2 = NULL;
	if ((list2 = (t_list2*)malloc(sizeof(t_list2))))
	{
		if (content == NULL)
		{
			list2->content = NULL;
			list2->content_size = 0;
		}
		else
		{
			if (!(list2->content = malloc(content_size)))
			{
				free(list2);
				return (NULL);
			}
			ft_memcpy(list2->content, content, content_size);
			list2->content_size = content_size;
		}
		list2->next = NULL;
		list2->prev = NULL;
	}
	return (list2);
}
