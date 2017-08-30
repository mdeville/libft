/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:04:17 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/31 00:07:34 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_matrix_free(void ***matrix, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free((*matrix)[i++]);
	free(*matrix);
	*matrix = NULL;
}
