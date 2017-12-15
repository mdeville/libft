/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printn_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:05:48 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 14:09:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printn_fd(int n, va_list *ap)
{
	int *res;

	res = va_arg(*ap, int *);
	if (!res)
		return ;
	*res = n;
}
