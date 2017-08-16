/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:34:29 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/16 16:49:50 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = dest;
	ptr2 = src;
	while (n)
	{
		*ptr1 = *ptr2;
		if (*ptr2 == (unsigned char)c)
			return (ptr1 + 1);
		ptr1++;
		ptr2++;
		n--;
	}
	return (NULL);
}
