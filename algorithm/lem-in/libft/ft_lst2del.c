/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:11:00 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/09/24 18:21:02 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_lst2del(t_list2 **last, void (*del)(void *, size_t))
{
	if (*last)
	{
		if ((*last)->next)
		{
			ft_lst2del(&(*last)->next, (*del));
		}
		ft_lst2delone(last, (*del));
	}
	return (NULL);
}
