/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcugni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 23:40:57 by zcugni            #+#    #+#             */
/*   Updated: 2018/11/05 23:40:58 by zcugni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_g_err(void)
{
	if (g_err->str)
		ft_strdel(&g_err->str);
	if (g_err)
		ft_memdel((void **)&g_err);
}

static void	display_errno(void)
{
	char *str;

	if (g_err)
		free_g_err();
	str = strerror(errno);
	ft_printf("%s\n", str);
	ft_strdel(&str);
	exit(errno);
}

static void	finish_gnl(void)
{
	int		read;

	if (g_err->line)
		ft_strdel(&g_err->line);
	read = get_next_line(g_err->fd, &g_err->line, '\n');
	while (read > 0)
	{
		ft_strdel(&g_err->line);
		read = get_next_line(g_err->fd, &g_err->line, '\n');
	}
	ft_strdel(&g_err->line);
}

void		free_start(void)
{
	t_list *tmp;

	tmp = NULL;
	if (!g_asm_inf->size_added && g_asm_inf->binary_list->next
					&& g_asm_inf->binary_list->next->next
					&& g_asm_inf->binary_list->next->next->next)
		tmp = g_asm_inf->binary_list->next->next->next;
	else if (g_asm_inf->size_added)
	{
		if (g_asm_inf->binary_list->next->next->next->next)
			tmp = g_asm_inf->binary_list->next->next->next->next;
		if (g_asm_inf->binary_list->next->next->next)
			free(g_asm_inf->binary_list->next->next->next);
		if (g_asm_inf->binary_list->next->next)
			free(g_asm_inf->binary_list->next->next->content);
	}
	if (g_asm_inf->binary_list->next && g_asm_inf->binary_list->next->next)
		free(g_asm_inf->binary_list->next->next);
	if (g_asm_inf->binary_list->next)
		free(g_asm_inf->binary_list->next);
	if (g_asm_inf->binary_list)
		free(g_asm_inf->binary_list);
	g_asm_inf->binary_list = tmp;
}

void		free_all(int err)
{
	if (g_asm_inf)
	{
		if (g_asm_inf->binary_list)
			free_start();
		ft_lstdel(&g_asm_inf->binary_list, 1, free);
		rbt_clear(&g_asm_inf->lbl_tree, free, 1);
		ft_lstdel(&g_asm_inf->holder_lst, 1, free_list_node);
		ft_memdel((void **)&g_asm_inf);
	}
	if (err == -1)
	{
		if (g_err)
			finish_gnl();
		display_errno();
	}
	else if (err != 0)
	{
		display_custom_err(err);
		finish_gnl();
		free_g_err();
		exit(err);
	}
	finish_gnl();
	free_g_err();
}
