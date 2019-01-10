/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:41:39 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/08 14:26:40 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define BUFF_SIZE 8
# define ERROR -1

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef	struct	s_list2
{
	void			*content;
	size_t			content_size;
	struct s_list2	*prev;
	struct s_list2	*next;
}				t_list2;

typedef struct	s_gnl
{
	char	*str;
	char	*tmp;
	int		status;
	t_list	*ltmp;
}				t_gnl;

typedef struct	s_btree
{
	void			*item;
	struct s_btree	*left;
	struct s_btree	*right;
}				t_btree;

enum			e_rb_color
{
	RB_bLACK,
	RB_RED
};

typedef struct	s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*data;
	enum e_rb_color		color;
}				t_rb_node;

/*
** is ?
*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isinteger(char *str);
int				ft_islower(int c);
int				ft_isprime(int n);
int				ft_isprint(int c);
int				ft_isupper(int c);

/*
** memory
*/

void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);

/*
** print
*/

size_t			ft_putchar(char c);
size_t			ft_putwchar(size_t chr);
size_t			ft_putnwchar(wchar_t *str, size_t n);
size_t			ft_putchar_fd(char c, int fd);
size_t			ft_putendl(const char *s);
size_t			ft_putendl_fd(const char *s, int fd);
size_t			ft_putnbr(int n);
size_t			ft_putnbr_fd(int n, int fd);
size_t			ft_putstr(const char *str);
size_t			ft_putwstr(wchar_t *str);
size_t			ft_putstr_fd(const	char *s, int fd);


/*
** character
*/

int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** string
*/

int				ft_atoi(const char *str);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlen(const char *s);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src,
				size_t size);
size_t			ft_countchr(char *str, char search);
size_t			ft_countnchr(char *str, int len, char search);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strnew_ch(size_t size, char c);
char			*ft_strnstr(const char *h, const char *n, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strdup(const char *s1);
char			**ft_strsplit(char const *s, char c);


/*
** string array
*/

int				ft_array_search(char *search, char **array);
size_t			ft_count(char **s);
void			ft_strtabiter(char **s, void (*f)(char **), int self);

/*
** w str/char
*/

size_t			ft_wstrlen(wchar_t *str);
size_t			ft_wcharlen(int chr);

/*
** int + math
*/

char			*ft_itoa(intmax_t n);
char			*ft_itoa_base(uintmax_t n, const char *base);
void			ft_swap(intmax_t *a, intmax_t *b);
int				ft_abs(int c);
intmax_t		ft_min(intmax_t a, intmax_t b);
intmax_t		ft_max(intmax_t a, intmax_t b);
int				ft_nextprime(int n);
int				ft_pow(int nb, int power);
int				ft_sqrt(int n);
double			ft_norme(double x, double y);
void			ft_qsort(int *tab, int start, int end);

/*
**	liste chainée
*/

void			ft_del(void *s, size_t i);
void			ft_lstadd(t_list **alst, t_list *new);
t_list			*ft_lstcpy(t_list *la);
t_list			*ft_lstncpy(t_list *src, int len);
t_list			*ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list			*ft_lstend(t_list *list);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstinsert(t_list *list, t_list *element);
size_t			ft_lstlen(t_list *list);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstpop(t_list *del, t_list *node);
void			ft_lstprint(t_list *lst);
void			ft_lstnprint(t_list *lst, int len);
t_list			*ft_lstsort(t_list *head,
					int (*f)(t_list *node1, t_list *node2));
void			ft_lstswap(t_list *node1, t_list *node2);

/*
**	liste doublement chainée
*/

void			ft_lst2add(t_list2 **alst2, t_list2 *new);
t_list2			*ft_lst2cpy(t_list2 *la);
t_list2			*ft_lst2ncpy(t_list2 *src, int len);
t_list2			*ft_lst2del(t_list2 **alst2, void (*del)(void *, size_t));
void			ft_lst2delone(t_list2 **alst2, void (*del)(void*, size_t));
t_list2			*ft_lst2end(t_list2 *list2);
void			ft_lst2iter(t_list2 *lst2, void (*f)(t_list2 *elem));
t_list2			*ft_lst2insert(t_list2 *list2, t_list2 *element);
size_t			ft_lst2len(t_list2 *list2);
t_list2			*ft_lst2map(t_list2 *lst2, t_list2 *(*f)(t_list2 *elem));
t_list2			*ft_lst2new(void const *content, size_t content_size);
t_list2			*ft_lst2pop(t_list2 *del, t_list2 *node);
void			ft_lst2print(t_list2 *lst2);
void			ft_lst2nprint(t_list2 *lst2, int len);
t_list2			*ft_lst2sort(t_list2 *head,
					int (*f)(t_list2 *node1, t_list2 *node2));
void			ft_lst2swap(t_list2 *node1, t_list2 *node2);

/*
**	arbre binaire
*/

t_btree			*ft_btrnew(void *item);
void			ft_btriterpre(t_btree *root, void (*f)(void *));
void			ft_btritersu(t_btree *root, void (*f)(void *));
void			ft_btriterin(t_btree *root, void (*f)(void *));
int				ft_btrcount(t_btree *root);
t_btree			*ft_btrsearch(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int				ft_btrinsert(t_btree **root, void *item, int (*cmpf)(void *, void *));

/*
**	read files
*/

int				get_next_line(const int fd, char **line);

#endif
