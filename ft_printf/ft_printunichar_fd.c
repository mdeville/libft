/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunichar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:22:35 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 14:12:39 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printunichar_fd(const int fd, t_token token, va_list *ap)
{
	char			utf8[4];
	int				len;
	unsigned int	c;
	int				cpt;

	c = (unsigned int)va_arg(*ap, wint_t);
	len = to_utf8(c, utf8);
	cpt = (token.width > len) ? token.width : len;
	if (!ft_strchr(token.flags, '-'))
	{
		while (token.width-- > len)
			write(fd, " ", 1);
	}
	write(fd, utf8, len);
	while (token.width-- > len)
		write(fd, " ", 1);
	return (cpt);
}
