/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:56:22 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/22 20:45:42 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	if (size == 0)
		return (NULL);
	ptr = (unsigned char *)malloc(size);
	if (!ptr)
		return (NULL);
	while (size)
	{
		ptr[size] = 0;
		size--;
	}
	ptr[size] = 0;
	return ((void *)ptr);
}
