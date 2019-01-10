/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:06:07 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:06:11 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

char	*ft_get_name(t_list *node)
{
	if (node)
		return (((t_room*)(node->content))->name);
	return (NULL);
}