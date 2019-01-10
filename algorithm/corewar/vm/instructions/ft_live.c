/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:16:15 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/11/18 13:44:13 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void	aux_verbose(t_pvm *vm, t_list *node)
{
	if (vm->verbose & 4)
	{
		ft_printf("P% 5d | live %d\n",
				node->content_size,
				vm->param[0]);
	}
}

int			ft_live(t_pvm *vm, t_list *node)
{
	int			nbr;
	t_process	*process;

	process = get_process(node);
	if (!(process->state % 2))
		process->state += 1;
	vm->sum_lives++;
	vm->param[0] = reverse_bytes(vm, process->pc + 1, 4);
	aux_verbose(vm, node);
	if ((nbr = ft_find_champ(vm, vm->param[0])) != -1)
	{
		vm->champions[nbr].nb_live++;
		vm->champions[nbr].l_live = vm->total_cycles;
		vm->last_live = vm->champions[nbr].nbr;
		if (vm->verbose & 1)
			ft_printf("Player %d (%s) is said to be alive\n",
				vm->champions[nbr].nbr * -1,
				vm->champions[nbr].header.prog_name);
	}
	if (vm->verbose & 16)
		print_adv(vm, process->pc, 5);
	process->last_live = vm->total_cycles;
	process->pc += 5;
	return (1);
}
