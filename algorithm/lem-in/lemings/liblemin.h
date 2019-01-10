/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:32:57 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 14:21:08 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLEMIN_H
# define LIBLEMIN_H

# include "libft.h"

typedef struct	s_config
{
	int		ants;
	t_list	*rooms;
	int		len;
	t_list	*start;
	t_list	*end;
	char	*matrice;
	t_list	*paths;
}				t_config;

typedef struct	s_room
{
	char	*name;
	int		number;
	int		x;
	int		y;
}				t_room;

/*
** parser
*/

int				ft_parser(t_config *config);
int				ft_comments(t_config *config, char *comment);
int				ft_rooms(t_config *config, char **str);
int				ft_links(t_config *config, char **str);

/*
** paths searcher
*/

int				ft_paths(t_config *config);
int				ft_find_paths(t_config *config, char *mat, char **ans, int i);
void			ft_colorify(t_config *config, char *mat, int i, int inc);
int				*ft_convert_str2int(t_config *config, t_list *path);
int				ft_sort_ans(t_list *node1, t_list *node2);
void			ft_delete_path(t_config *config);

/*
** output results
*/

int				ft_antswaltz(t_config *config);
int				ft_print_waltz(t_list *rooms, t_list *list);

/*
** fonction de récupération de données de la structure
*/

t_list			*ft_find_node(char *str, t_list *rooms);
t_list			*ft_find_node_bynbr(int nbr, t_list *nodes);
t_list			*ft_find_node_byname(char *str, t_list *rooms);
int				ft_get_number(t_list *node);
char			*ft_get_name(t_list *node);

/*
** fonction pour free list->content
*/

void			ft_del_path(void *content, size_t i);
void			ft_del_room(void *content, size_t i);
void			ft_del_void(void *content, size_t size);

/*
** fonction de debug
*/

int				ft_usage_error(int i);
void			ft_lstprint_room(t_list *list);
void			ft_lstprint_link(t_list *list);
void			ft_print_matrice(char *str, int len);
void			ft_print_info(t_config *config);
void			ft_print_path(t_list *list);

#endif
