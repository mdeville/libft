/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:43:55 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/07 17:53:05 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprintf(const char *format, va_list ap)
{
	int		res;
	va_list	cpy;

	va_copy(cpy, ap);
	res = ft_vfprintf(1, format, cpy);
	va_end(cpy);
	return (res);
}
