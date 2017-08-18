/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 20:51:25 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/18 22:08:29 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	len = ft_strlen(dst);
	size = size - len;
	i = 0;
	while (size && src[i])
	{
		dst[i + len] = src[i];
		size--;
		i++;
	}
	dst[i + len] = '\0';
	return (size);
}
