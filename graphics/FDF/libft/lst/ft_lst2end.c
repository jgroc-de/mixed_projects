/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:30:47 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 12:30:49 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the last node of a list2
*/

t_list2	*ft_lst2end(t_list2 *list2)
{
	if (list2)
	{
		while (list2->next)
			list2 = list2->next;
	}
	return (list2);
}
