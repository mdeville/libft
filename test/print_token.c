/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:09:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 13:59:37 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_token(const int fd, t_token t, va_list *ap, int cpt)
{
	if (t.specifier == '%')
		return (ft_printpercent_fd(fd, t));
	else if (t.specifier == 'C' || (t.specifier == 'c' && t.length == l))
		return (ft_printunichar_fd(fd, t, ap));
	else if (t.specifier == 'c')
		return (ft_printchar_fd(fd, t, ap));
	else if (t.specifier == 'S' || (t.specifier == 's' && t.length == l))
		return (ft_printunistr_fd(fd, t, ap));
	else if (t.specifier == 's')
		return (ft_printstr_fd(fd, t, ap));
	else if (t.specifier == 'd' || t.specifier == 'D' || t.specifier == 'i')
		return (ft_printint_fd(fd, t, ap));
	else if (t.specifier == 'u' || t.specifier == 'U')
		return (ft_printuint_fd(fd, t, ap));
	else if (t.specifier == 'o' || t.specifier == 'O')
		return (ft_printoctal_fd(fd, t, ap));
	else if (t.specifier == 'x' || t.specifier == 'X')
		return (ft_printhexa_fd(fd, t, ap));
	else if (t.specifier == 'p')
		return (ft_printpointer_fd(fd, t, ap));
	else if (t.specifier == 'b' || t.specifier == 'B')
		return (ft_printbin_fd(fd, t, ap));
	else if (t.specifier == 'n')
		ft_printn_fd(cpt, ap);
	return (0);
}
