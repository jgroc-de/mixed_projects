/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:09:50 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 19:35:11 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*copy;
	t_list	*save;
	t_list	*tmp;

	if (!(copy = ft_lstnew(NULL, 0)))
		return (NULL);
	save = copy;
	while (lst)
	{
		tmp = (*f)(lst);
		copy->content = tmp->content;
		copy->content_size = tmp->content_size;
		lst = lst->next;
		if (lst)
		{
			if (!(copy->next = ft_lstnew(NULL, 0)))
				return (NULL);
			copy = copy->next;
		}
	}
	return (save);
}
