/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 21:13:01 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/22 16:33:46 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
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

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
char				*ft_basename(char *path);
void				ft_dlstappend(t_dlist **alst, t_dlist *new);
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdel_back(
									t_dlist **alst,
									void (*del)(void *, size_t));
void				ft_dlstdel_front(
									t_dlist **alst,
									void (*del)(void *, size_t));
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstfilter(
								t_dlist **alst,
								int (*p)(t_dlist *),
								void (*del)(void *, size_t));
t_dlist				*ft_dlstnew(char const *content, size_t content_size);
void				ft_dlstprepend(t_dlist **alst, t_dlist *new);
void				ft_dlstreverse(t_dlist **alst);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isnumber(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstfilter(
								t_list **alst,
								int (*p)(t_list *),
								void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_lstpop(t_list **alst, size_t *content_size);
void				ft_lstreverse(t_list **alst);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
t_rbnode			*ft_rbnodenew(void const *content, size_t content_size);
int					ft_str_is_alpha(const char *str);
int					ft_str_is_lowercase(const char *str);
int					ft_str_is_numeric(const char *str);
int					ft_str_is_printable(const char *str);
int					ft_str_is_uppercase(const char *str);
char				*ft_strcapitalize(char *str);
int					ft_strcasecmp(const char *s1, const char *s2);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(size_t n, ...);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strnlen(const char *str, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strndup(char const *s, size_t n);
char				*ft_stpncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(
								const char *big,
								const char *little,
								size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strtrimc(char const *s, char c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_utoa_base(uintmax_t n, const char *base);
char				*ft_utoa(unsigned int n);
int					to_utf8(unsigned int c, char *utf8);
int					ft_isatty(int fd);

#endif
