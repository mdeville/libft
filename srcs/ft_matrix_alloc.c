/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 23:49:55 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/31 00:16:54 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	**ft_matrix_alloc(size_t x, size_t y)
{
	void	**res;
	size_t	i;

	res = (void **)malloc(x);
	if (!res)
		return (NULL);
	i = 0;
	while (i)
	{
		res[i++] = (void *)malloc(y);
		if (!res[i - 1])
		{
			ft_matrix_free(&res, i);
			return (NULL);
		}
	}
	return (res);
}
