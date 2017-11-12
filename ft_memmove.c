/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 20:18:49 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/16 22:43:39 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void	cpy_fd(unsigned char *dest, const unsigned char *src, size_t n)
{
	while (n)
	{
		*dest++ = *src++;
		n--;
	}
}

static void	cpy_bd(unsigned char *dest, const unsigned char *src, size_t n)
{
	while (n)
	{
		dest[n - 1] = src[n - 1];
		n--;
	}
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	int		diff;

	diff = src - dest;
	if (diff >= (int)n || diff <= -(int)n)
		return (ft_memcpy(dest, src, n));
	if (diff > 0)
		cpy_fd(dest, src, n);
	else if (diff < 0)
		cpy_bd(dest, src, n);
	return (dest);
}
