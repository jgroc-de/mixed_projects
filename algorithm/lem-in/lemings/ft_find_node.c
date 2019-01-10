/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:05:44 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:09:07 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

t_list	*ft_find_node_bynbr(int nbr, t_list *nodes)
{
	t_list	*tmp;

	tmp = nodes;
	while (tmp && ft_get_number(tmp) != nbr)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_list	*ft_find_node_byname(char *str, t_list *rooms)
{
	t_list	*tmp;

	tmp = rooms;
	while (tmp && !ft_strequ(ft_get_name(tmp), str))
	{
		tmp = tmp->next;
	}
	return (tmp);
}
