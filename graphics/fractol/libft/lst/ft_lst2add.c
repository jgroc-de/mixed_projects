/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:10:24 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 14:28:46 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst2add(t_list2 **last, t_list2 *new)
{
	if (new)
	{
		(*last)->prev = new;
		new->next = *last;
		new->prev = NULL;
		*last = new;
	}
}
