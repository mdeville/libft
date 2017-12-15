/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:42:30 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 14:13:30 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*zero_case(intmax_t n, char *ascii, int alen, t_token token)
{
	int		total;
	int		plus;
	int		space;
	char	*res;

	plus = ft_strchr(token.flags, '+') ? 1 : 0;
	space = ft_strchr(token.flags, ' ') ? 1 : 0;
	total = (n < 0 || plus || space) ? alen + 1 : alen;
	total = (token.width > total) ? token.width : total;
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (total >= 0)
	{
		if (alen >= 0)
			res[total--] = ascii[alen--];
		else if (plus && !total)
			res[total--] = (n < 0) ? '-' : '+';
		else if (space && !total)
			res[total--] = (n < 0) ? '-' : ' ';
		else if (!total && n < 0)
			res[total--] = '-';
		else
			res[total--] = '0';
	}
	return (res);
}

static char		*normal_case(intmax_t n, char *ascii, int alen, t_token token)
{
	int		total;
	int		plus;
	int		space;
	char	*res;

	plus = ft_strchr(token.flags, '+') ? 1 : 0;
	space = ft_strchr(token.flags, ' ') ? 1 : 0;
	total = (token.precision > alen) ? token.precision : alen;
	total = (n < 0 || plus || space) ? total + 1 : total;
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (total >= 0)
	{
		if (alen >= 0)
			res[total--] = ascii[alen--];
		else if (plus && !total)
			res[total--] = (n < 0) ? '-' : '+';
		else if (space && !total)
			res[total--] = (n < 0) ? '-' : ' ';
		else if (!total && n < 0)
			res[total--] = '-';
		else
			res[total--] = '0';
	}
	return (res);
}

static char		*apply_options(intmax_t n, char *ascii, int alen, t_token token)
{
	char	*res;

	if (token.precision == 0 && n == 0)
		res = ft_strchr(token.flags, '+') ? ft_strdup("+") : ft_strdup("");
	else if (token.precision == 1
		&& !ft_strchr(token.flags, '-')
		&& ft_strchr(token.flags, '0'))
		res = zero_case(n, ascii, alen, token);
	else
		res = normal_case(n, ascii, alen, token);
	free(ascii);
	return (res);
}

static intmax_t	convert(va_list *ap, t_length length, char spe)
{
	intmax_t n;

	n = va_arg(*ap, intmax_t);
	if (length == l || spe == 'D')
		n = (long)n;
	else if (length == hh)
		n = (char)n;
	else if (length == h)
		n = (short int)n;
	else if (length == ll)
		n = (long long int)n;
	else if (length == j)
		n = (intmax_t)n;
	else if (length == z)
		n = (size_t)n;
	else if (length == None)
		n = (int)n;
	return (n);
}

int				ft_printint_fd(const int fd, t_token token, va_list *ap)
{
	intmax_t	n;
	int			len;
	int			cpt;
	char		*tmp;

	n = convert(ap, token.length, token.specifier);
	if (!(tmp = ft_printitoa(n)))
		return (0);
	if (!(tmp = apply_options(n, tmp, ft_strlen(tmp), token)))
		return (0);
	len = ft_strlen(tmp);
	cpt = (token.width > len) ? token.width - len + len : len;
	if (!ft_strchr(token.flags, '-'))
	{
		while (token.width-- > len)
			write(fd, " ", 1);
	}
	write(fd, tmp, len);
	free(tmp);
	while (token.width-- > len)
		write(fd, " ", 1);
	return (cpt);
}
