/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2lcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:20:12 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/09/24 18:20:13 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_lst2lcpy(t_list2 *src, int len)
{
	t_list2	*cpy;
	t_list2	*tmp;

	if (!(src))
		return (NULL);
	if ((cpy = ft_lst2new(NULL, 0)))
	{
		tmp = cpy;
		tmp->prev = NULL;
		while (src && len--)
		{
			if (!(tmp->content = ft_memalloc(sizeof(char) * src->content_size)))
				return (ft_lst2del(&cpy, &ft_del));
			ft_memcpy(tmp->content, src->content, src->content_size);
			tmp->content_size = src->content_size;
			src = src->next;
			if (src && len)
			{
				if (!(tmp->next = ft_lst2new(NULL, 0)))
					return (ft_lst2del(&cpy, &ft_del));
				tmp->next->prev = tmp;
				tmp = tmp->next;
			}
		}
	}
	return (cpy);
}
