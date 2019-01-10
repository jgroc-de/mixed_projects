/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:20:43 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/09/24 18:20:45 by jgroc-de         ###   ########.fr       */
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
