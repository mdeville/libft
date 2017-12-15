/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:10:00 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 14:10:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*zero_case(
						char *ascii,
						int alen,
						t_token token)
{
	int		total;
	char	*res;

	total = alen + 2;
	total = (token.width > total) ? token.width : total;
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (total >= 0)
	{
		if (alen >= 0)
			res[total--] = ascii[alen--];
		else if (total == 1)
			res[total--] = 'x';
		else
			res[total--] = '0';
	}
	return (res);
}

static char			*normal_case(
						char *ascii,
						int alen,
						t_token token)
{
	int		total;
	char	*res;

	total = (token.precision > alen) ? token.precision + 2 : alen + 2;
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (total >= 0)
	{
		if (alen >= 0)
			res[total--] = ascii[alen--];
		else if (total == 1)
			res[total--] = 'x';
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
		res = ft_strdup("0x");
	else if (token.precision == 1
		&& !ft_strchr(token.flags, '-')
		&& ft_strchr(token.flags, '0'))
		res = zero_case(ascii, alen, token);
	else
		res = normal_case(ascii, alen, token);
	free(ascii);
	return (res);
}

int					ft_printpointer_fd(const int fd, t_token token, va_list *ap)
{
	uintmax_t	n;
	int			len;
	int			cpt;
	char		*tmp;

	n = va_arg(*ap, uintmax_t);
	if (!(tmp = ft_utoa_base(n, "0123456789abcdef")))
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
