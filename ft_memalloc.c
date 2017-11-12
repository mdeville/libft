/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:56:22 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/12 20:32:22 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (size == 0)
		return (NULL);
	ptr = (unsigned char *)malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = 0;
	return ((void *)ptr);
}
