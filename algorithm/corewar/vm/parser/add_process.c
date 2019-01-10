/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:51:21 by alouisy-          #+#    #+#             */
/*   Updated: 2018/11/17 22:07:47 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

inline int	add_process(t_pvm *vm)
{
	t_list		*node;
	t_list		*tmp;
	t_process	process;

	init_process(&process, vm);
	if (!(node = ft_lstnew2(&process, sizeof(process))))
		return (ft_strerror("Malloc fail", 0));
	node->content_size = ++vm->pid;
	tmp = vm->stack;
	vm->stack = node;
	node->next = tmp;
	return (1);
}
