/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:14:24 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/09/24 18:15:10 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintl(t_list *lst, int len)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && len--)
	{
		if (tmp->content)
		{
			if (tmp->content_size == 8)
				ft_putnbr(*(intmax_t *)(tmp->content));
			else
				ft_putstr((char*)tmp->content);
		}
		else
			ft_putendl("NULL");
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	ft_lstprint(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->content)
		{
			if (tmp->content_size == 8)
				ft_putnbr(*(intmax_t *)(tmp->content));
			else
				ft_putstr((char*)tmp->content);
		}
		else
			ft_putendl("NULL");
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
