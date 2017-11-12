/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:07:36 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/12 22:27:54 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_printable(const char *str)
{
	while (*str)
	{
		if (!ft_isprint(*str++))
			return (0);
	}
	return (1);
}
