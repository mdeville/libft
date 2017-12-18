/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:02:05 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 20:32:11 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include "libft.h"

/*
** Typedefs to restore sanity
*/

typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;

typedef enum					e_length
{
	None,
	hh,
	h,
	l,
	ll,
	j,
	z
}								t_length;

typedef struct					s_token
{
	char			flags[6];
	int				width;
	int				precision;
	t_length		length;
	char			specifier;
}								t_token;

/*
** Main functions
*/

int								ft_fprintf(
									const int fd,
									const char *format,
									...);

int								ft_printf(
									const char *format,
									...);

int								ft_vprintf(
									const char *format,
									va_list ap);

int								ft_vfprintf(
									const int fd,
									const char *format,
									va_list ap);

/*
** Parsing functions
*/

t_token							parse_token(
									const char *str,
									size_t *i,
									va_list *ap);

/*
** Printing functions
*/

int								print_token(
									const int fd,
									t_token token,
									va_list *ap,
									int cpt);

int								ft_printpercent_fd(
									const int fd,
									t_token token);

int								ft_printchar_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printstr_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printint_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printuint_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printoctal_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printhexa_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printbin_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printpointer_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printunichar_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printunistr_fd(
									const int fd,
									t_token token,
									va_list *ap);

void							ft_printn_fd(
									int n,
									va_list *ap);

/*
** Utilities
*/

char							*ft_printitoa(intmax_t n);

#endif
