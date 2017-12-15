/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:48:07 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 14:10:29 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			ft_printstr_fd(const int fd, t_token t, va_list *ap)
{
	int		len;
	char	*str;
	int		cpt;

	str = va_arg(*ap, char *);
	if (!str)
		return (null_case(fd, t));
	len = ft_strlen(str);
	len = (t.precision >= 0 && t.precision < len) ? t.precision : len;
	cpt = len;
	if (!ft_strchr(t.flags, '-'))
		while (t.width-- > len)
		{
			write(fd, " ", 1);
			cpt++;
		}
	write(fd, str, len);
	while (t.width-- > len)
	{
		write(fd, " ", 1);
		cpt++;
	}
	return (cpt);
}
