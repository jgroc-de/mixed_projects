/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:17:23 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/11/15 13:07:06 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort(int *tab, int start, int end)
{
	int left;
	int right;
	int pivot;

	left = start;
	right = end;
	pivot = tab[start];
	if (start >= end)
		return ;
	while (1)
	{
		while (tab[right] > pivot)
			right--;
		while (tab[left] < pivot)
			left--;
		if (left < right)
			ft_swap((intmax_t*)(tab + left), (intmax_t*)(tab + right));
		else
			break ;
	}
	ft_qsort(tab, start, right);
	ft_qsort(tab, right + 1, end);
}
