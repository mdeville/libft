/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 21:13:01 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/13 18:56:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# define IS_WS(c) (c == ' ' || c == '\n' || c == '\t')

enum				e_color {RED, BLACK, NONE};

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_rbnode
{
	enum e_color	color;
	void			*content;
	size_t			content_size;
	struct s_rbnode	*left;
	struct s_rbnode	*right;
}					t_rbnode;

/* ft_atoi.c */
int ft_atoi(const char *str);
/* ft_bzero.c */
void ft_bzero(void *s, size_t n);
/* ft_dlstappend.c */
void ft_dlstappend(t_dlist **alst, t_dlist *new);
/* ft_dlstdel.c */
void ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
/* ft_dlstdel_back.c */
void ft_dlstdel_back(t_dlist **alst, void (*del)(void *, size_t));
/* ft_dlstdel_front.c */
void ft_dlstdel_front(t_dlist **alst, void (*del)(void *, size_t));
/* ft_dlstdelone.c */
void ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
/* ft_dlstfilter.c */
void ft_dlstfilter(
				t_dlist **alst,
				int (*p)(t_dlist *),
				void (*del)(void *, size_t));
/* ft_dlstnew.c */
t_dlist *ft_dlstnew(char const *content, size_t content_size);
/* ft_dlstprepend.c */
void ft_dlstprepend(t_dlist **alst, t_dlist *new);
/* ft_dlstreverse.c */
void ft_dlstreverse(t_dlist **alst);
/* ft_isalnum.c */
int ft_isalnum(int c);
/* ft_isalpha.c */
int ft_isalpha(int c);
/* ft_isascii.c */
int ft_isascii(int c);
/* ft_isblank.c */
int ft_isblank(int c);
/* ft_iscntrl.c */
int ft_iscntrl(int c);
/* ft_isdigit.c */
int ft_isdigit(int c);
/* ft_isgraph.c */
int ft_isgraph(int c);
/* ft_islower.c */
int ft_islower(int c);
/* ft_isnumber.c */
int ft_isnumber(int c);
/* ft_isprint.c */
int ft_isprint(int c);
/* ft_isspace.c */
int ft_isspace(int c);
/* ft_isupper.c */
int ft_isupper(int c);
/* ft_isxdigit.c */
int ft_isxdigit(int c);
/* ft_itoa.c */
char *ft_itoa(int n);
/* ft_lstadd.c */
void ft_lstadd(t_list **alst, t_list *new);
/* ft_lstdel.c */
void ft_lstdel(t_list **alst, void (*del)(void *, size_t));
/* ft_lstdelone.c */
void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
/* ft_lstfilter.c */
void ft_lstfilter(
				t_list **alst,
				int (*p)(t_list *),
				void (*del)(void *, size_t));
/* ft_lstiter.c */
void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
/* ft_lstmap.c */
t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/* ft_lstnew.c */
t_list *ft_lstnew(void const *content, size_t content_size);
/* ft_lstpop.c */
void *ft_lstpop(t_list **alst, size_t *content_size);
/* ft_lstreverse.c */
void ft_lstreverse(t_list **alst);
/* ft_memalloc.c */
void *ft_memalloc(size_t size);
/* ft_memccpy.c */
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
/* ft_memchr.c */
void *ft_memchr(const void *s, int c, size_t n);
/* ft_memcmp.c */
int ft_memcmp(const void *s1, const void *s2, size_t n);
/* ft_memcpy.c */
void *ft_memcpy(void *dest, const void *src, size_t n);
/* ft_memdel.c */
void ft_memdel(void **ap);
/* ft_memmove.c */
void *ft_memmove(void *dest, const void *src, size_t len);
/* ft_memset.c */
void *ft_memset(void *s, int c, size_t n);
/* ft_putchar.c */
void ft_putchar(char c);
/* ft_putchar_fd.c */
void ft_putchar_fd(char c, int fd);
/* ft_putendl.c */
void ft_putendl(char const *s);
/* ft_putendl_fd.c */
void ft_putendl_fd(char const *s, int fd);
/* ft_putnbr.c */
void ft_putnbr(int n);
/* ft_putnbr_fd.c */
void ft_putnbr_fd(int n, int fd);
/* ft_putstr.c */
void ft_putstr(char const *s);
/* ft_putstr_fd.c */
void ft_putstr_fd(char const *s, int fd);
/* ft_rbnodenew.c */
t_rbnode *ft_rbnodenew(void const *content, size_t content_size);
/* ft_str_is_alpha.c */
int ft_str_is_alpha(const char *str);
/* ft_str_is_lowercase.c */
int ft_str_is_lowercase(const char *str);
/* ft_str_is_numeric.c */
int ft_str_is_numeric(const char *str);
/* ft_str_is_printable.c */
int ft_str_is_printable(const char *str);
/* ft_str_is_uppercase.c */
int ft_str_is_uppercase(const char *str);
/* ft_strcapitalize.c */
char *ft_strcapitalize(char *str);
/* ft_strcasecmp.c */
int ft_strcasecmp(const char *s1, const char *s2);
/* ft_strcat.c */
char *ft_strcat(char *dest, const char *src);
/* ft_strchr.c */
char *ft_strchr(const char *s, int c);
/* ft_strclr.c */
void ft_strclr(char *s);
/* ft_strcmp.c */
int ft_strcmp(const char *s1, const char *s2);
/* ft_strcpy.c */
char *ft_strcpy(char *dest, const char *src);
/* ft_strdel.c */
void ft_strdel(char **as);
/* ft_strdup.c */
char *ft_strdup(const char *s1);
/* ft_strequ.c */
int ft_strequ(char const *s1, char const *s2);
/* ft_striter.c */
void ft_striter(char *s, void (*f)(char *));
/* ft_striteri.c */
void ft_striteri(char *s, void (*f)(unsigned int, char *));
/* ft_strjoin.c */
char *ft_strjoin(char const *s1, char const *s2);
/* ft_strlcat.c */
size_t ft_strlcat(char *dst, const char *src, size_t size);
/* ft_strlen.c */
size_t ft_strlen(const char *str);
/* ft_strmap.c */
char *ft_strmap(char const *s, char (*f)(char));
/* ft_strmapi.c */
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
/* ft_strncasecmp.c */
int ft_strncasecmp(const char *s1, const char *s2, size_t n);
/* ft_strncat.c */
char *ft_strncat(char *dest, const char *src, size_t n);
/* ft_strncmp.c */
int ft_strncmp(const char *s1, const char *s2, size_t n);
/* ft_strncpy.c */
char *ft_strncpy(char *dest, const char *src, size_t len);
/* ft_strndup.c */
char *ft_strndup(char const *s, size_t n);
/* ft_strnequ.c */
int ft_strnequ(char const *s1, char const *s2, size_t n);
/* ft_strnew.c */
char *ft_strnew(size_t size);
/* ft_strnstr.c */
char *ft_strnstr(const char *big, const char *little, size_t len);
/* ft_strrchr.c */
char *ft_strrchr(const char *s, int c);
/* ft_strsplit.c */
char **ft_strsplit(char const *s, char c);
/* ft_strstr.c */
char *ft_strstr(const char *haystack, const char *needle);
/* ft_strsub.c */
char *ft_strsub(char const *s, unsigned int start, size_t len);
/* ft_strtrim.c */
char *ft_strtrim(char const *s);
/* ft_strtrimc.c */
char *ft_strtrimc(char const *s, char c);
/* ft_tolower.c */
int ft_tolower(int c);
/* ft_toupper.c */
int ft_toupper(int c);

#endif
