/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 20:18:49 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/12 20:37:17 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void	cpy_bd(unsigned char *dest, const unsigned char *src, size_t n)
{
	size_t i;

	i = n - 1;
	while (i > 0)
	{
		dest[i] = src[i];
		i--;
	}
	dest[0] = src[0];
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src < dest && src + n >= dest)
		cpy_bd(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
