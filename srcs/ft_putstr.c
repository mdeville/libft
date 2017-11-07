/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:57:28 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/07 17:43:32 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>

void	ft_putstr(char const *s)
{
	size_t len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}
