/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_size_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:55:18 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/24 13:04:19 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char	*ft_d_size_z(va_list *ap, t_printf *all)
{
	ssize_t	nbr;

	nbr = va_arg(*ap, ssize_t);
	all->str = ft_itoa(nbr);
	return (all->str);
}

char	*ft_d_size_(va_list *ap, t_printf *all)
{
	int	nbr;

	nbr = va_arg(*ap, int);
	all->str = ft_itoa(nbr);
	return (all->str);
}
