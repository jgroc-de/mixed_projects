/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:05:32 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:06:11 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

void	ft_del_path(void *content, size_t i)
{
	(void)i;
	ft_memdel(&content);
}

void	ft_del_room(void *content, size_t i)
{
	(void)i;
	ft_strdel(&(((t_room*)(content))->name));
	free(content);
}

void	ft_del_void(void *content, size_t size)
{
	(void)content;
	(void)size;
}
