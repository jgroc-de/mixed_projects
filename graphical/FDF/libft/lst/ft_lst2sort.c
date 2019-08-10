/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:14:24 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 12:29:04 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	mergesort!!
*/

static t_list2	*aux_select(t_list2 **l1, t_list2 **l2,
		int (*f)(t_list2 *node1, t_list2 *node2))
{
	t_list2	*select;

	if (!(*l2) || (*l1 && f(*l1, *l2) <= 0))
	{
		select = *l1;
		(*l1) = (*l1)->next;
	}
	else
	{
		select = *l2;
		(*l2) = (*l2)->next;
	}
	return (select);
}

static t_list2	*aux_merge(t_list2 *l1, t_list2 *l2,
		int (*f)(t_list2 *node1, t_list2 *node2))
{
	t_list2	*tmp;
	t_list2	*head;

	head = aux_select(&l1, &l2, f);
	tmp = head;
	while (l2 || l1)
	{
		tmp->next = aux_select(&l1, &l2, f);
		tmp = tmp->next;
	}
	return (head);
}

t_list2			*ft_lst2sort(t_list2 *l1, int (*f)(t_list2 *node1,
			t_list2 *node2))
{
	t_list2	*tmp;
	t_list2	*l2;
	int		len;

	l2 = NULL;
	len = ft_lst2len(l1);
	if (len > 2)
	{
		len = len / 2;
		while (len--)
		{
			tmp = l1;
			l1 = l1->next;
			tmp->next = l2;
			l2 = tmp;
		}
		l1 = ft_lst2sort(l1, f);
		l2 = ft_lst2sort(l2, f);
		l1 = aux_merge(l1, l2, f);
	}
	else if (l1 && l1->next && f(l1, l1->next) > 0)
		ft_lst2swap(l1, l1->next);
	return (l1);
}
