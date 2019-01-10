/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:20:29 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/09/24 18:20:31 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_lst2cpy(t_list2 *src)
{
	t_list2	*cpy;
	t_list2	*tmp;

	cpy = NULL;
	if (!(src))
		return (NULL);
	if ((cpy = ft_lst2new(NULL, 0)))
	{
		tmp = cpy;
		tmp->prev = NULL;
		while (src)
		{
			if (!(tmp->content = ft_memalloc(sizeof(char) * src->content_size)))
				return (NULL);
			ft_memcpy(tmp->content, src->content, src->content_size);
			tmp->content_size = src->content_size;
			src = src->next;
			if (src)
			{
				if (!(tmp->next = ft_lst2new(NULL, 0)))
					return (NULL);
				tmp->next->prev = tmp;
				tmp = tmp->next;
			}
		}
	}
	return (cpy);
}
