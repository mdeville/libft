/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunistr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:32:49 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 14:12:24 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unistrlen(const wchar_t *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] < 0x80)
			len += 1;
		else if (str[i] < 0x800)
			len += 2;
		else if (str[i] < 0x10000)
			len += 3;
		else if (str[i] <= 0x10FFFF)
			len += 4;
		else
			len += 3;
		i++;
	}
	return (len);
}

static int	null_case(const int fd, t_token t)
{
	int		cpt;
	int		len;
	char	buff[7];

	ft_strcpy(buff, "(null)");
	len = 6;
	len = (t.precision >= 0 && t.precision < len) ? t.precision : len;
	cpt = len;
	if (!ft_strchr(t.flags, '-'))
		while (t.width-- > len)
		{
			write(fd, " ", 1);
			cpt++;
		}
	write(fd, buff, len);
	while (t.width-- > len)
	{
		write(fd, " ", 1);
		cpt++;
	}
	return (cpt);
}

static int	wchar_to_utf(const wchar_t *unicode, char **utf8)
{
	int i;
	int j;
	int utflen;

	i = 0;
	j = 0;
	if (!(utflen = ft_unistrlen(unicode)))
		return (0);
	if (!(*utf8 = (char *)malloc(utflen + 1)))
		return (0);
	while (unicode[i])
		j += to_utf8(unicode[i++], *utf8 + j);
	(*utf8)[j] = '\0';
	return (j);
}

int			ft_printunistr_fd(const int fd, t_token t, va_list *ap)
{
	char	*utf8;
	wchar_t	*unicode;
	int		len;
	int		cpt;

	unicode = va_arg(*ap, wchar_t *);
	if (!unicode)
		return (null_case(fd, t));
	if (!(len = wchar_to_utf(unicode, &utf8)))
		return (0);
	len = (t.precision >= 0 && t.precision < len) ? t.precision : len;
	cpt = (t.width > len) ? t.width : len;
	if (!ft_strchr(t.flags, '-'))
	{
		while (t.width-- > len)
			write(fd, " ", 1);
	}
	write(fd, utf8, len);
	while (t.width-- > len)
		write(fd, " ", 1);
	free(utf8);
	return (cpt);
}
