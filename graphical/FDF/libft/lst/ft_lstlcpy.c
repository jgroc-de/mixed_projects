/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:20:12 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/09/24 18:20:13 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlcpy(t_list *src, int len)
{
	t_list	*cpy;
	t_list	*tmp;

	if (!(src))
		return (NULL);
	if ((cpy = ft_lstnew(NULL, 0)))
	{
		tmp = cpy;
		while (src && len--)
		{
			if (!(tmp->content = ft_memalloc(sizeof(char) * src->content_size)))
				return (ft_lstdel(&cpy, &ft_del));
			ft_memcpy(tmp->content, src->content, src->content_size);
			tmp->content_size = src->content_size;
			src = src->next;
			if (src && len)
			{
				if (!(tmp->next = ft_lstnew(NULL, 0)))
					return (ft_lstdel(&cpy, &ft_del));
				tmp = tmp->next;
			}
		}
	}
	return (cpy);
}
