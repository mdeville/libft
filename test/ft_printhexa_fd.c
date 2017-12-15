/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:09:17 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 14:07:34 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*zero_case(
						uintmax_t n,
						char *ascii,
						int alen,
						t_token token)
{
	int		total;
	int		prefix;
	char	*res;

	prefix = ft_strchr(token.flags, '#') ? 1 : 0;
	total = (prefix && n) ? alen + 1 : alen;
	total = (token.width > total) ? token.width : total;
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (total >= 0)
	{
		if (alen >= 0)
			res[total--] = ascii[alen--];
		else if (n && prefix && total == 1)
			res[total--] = token.specifier;
		else
			res[total--] = '0';
	}
	return (res);
}

static char			*normal_case(
						uintmax_t n,
						char *ascii,
						int alen,
						t_token token)
{
	int		total;
	int		prefix;
	char	*res;

	prefix = ft_strchr(token.flags, '#') ? 1 : 0;
	total = (token.precision > alen) ? token.precision : alen;
	total = (prefix && n) ? total + 2 : total;
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (total >= 0)
	{
		if (alen >= 0)
			res[total--] = ascii[alen--];
		else if (n && prefix && total == 1)
			res[total--] = token.specifier;
		else
			res[total--] = '0';
	}
	return (res);
}

static char			*apply_options(
						uintmax_t n,
						char *ascii,
						int alen,
						t_token token)
{
	char	*res;

	if (token.precision == 0 && n == 0)
		res = ft_strdup("");
	else if (token.precision == 1
		&& !ft_strchr(token.flags, '-')
		&& ft_strchr(token.flags, '0'))
		res = zero_case(n, ascii, alen, token);
	else
		res = normal_case(n, ascii, alen, token);
	free(ascii);
	return (res);
}

static uintmax_t	convert(va_list *ap, t_length length)
{
	uintmax_t n;

	n = va_arg(*ap, uintmax_t);
	if (length == l)
		n = (unsigned long)n;
	else if (length == hh)
		n = (unsigned char)n;
	else if (length == h)
		n = (unsigned short int)n;
	else if (length == ll)
		n = (unsigned long long int)n;
	else if (length == j)
		n = (uintmax_t)n;
	else if (length == z)
		n = (size_t)n;
	else if (length == None)
		n = (unsigned int)n;
	return (n);
}

int					ft_printhexa_fd(const int fd, t_token token, va_list *ap)
{
	uintmax_t	n;
	int			len;
	int			cpt;
	char		*tmp;

	n = convert(ap, token.length);
	if (!(tmp = (token.specifier == 'x') ?
				ft_utoa_base(n, "0123456789abcdef") :
				ft_utoa_base(n, "0123456789ABCDEF")))
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
