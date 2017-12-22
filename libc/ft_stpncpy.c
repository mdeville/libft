/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:09:07 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/22 15:16:49 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stpncpy(char *dest, const char *src, size_t n)
{
	size_t size;

	size = ft_strnlen(src, n);
	ft_memcpy(dest, src, size);
	dest += size;
	if (size == n)
		return (dest);
	return (ft_memset(dest, '\0', n - size));
}
