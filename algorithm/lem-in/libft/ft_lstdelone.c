/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:11:07 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 14:33:08 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **last, void (*del)(void *, size_t))
{
	(*last)->next = NULL;
	(*del)((*last)->content, (*last)->content_size);
	ft_memdel((void**)last);
}
