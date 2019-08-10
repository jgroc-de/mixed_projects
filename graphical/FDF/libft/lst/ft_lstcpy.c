/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:20:29 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/09/24 18:20:31 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *src)
{
	t_list	*cpy;
	t_list	*tmp;

	cpy = NULL;
	if (!(src))
		return (NULL);
	if ((cpy = ft_lstnew(NULL, 0)))
	{
		tmp = cpy;
		while (src)
		{
			if (!(tmp->content = ft_memalloc(sizeof(char) * src->content_size)))
				return (NULL);
			ft_memcpy(tmp->content, src->content, src->content_size);
			tmp->content_size = src->content_size;
			src = src->next;
			if (src)
			{
				if (!(tmp->next = ft_lstnew(NULL, 0)))
					return (NULL);
				tmp = tmp->next;
			}
		}
	}
	return (cpy);
}
