/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:22:58 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/22 14:09:57 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	nbrlen(unsigned int n)
{
	int cpt;

	cpt = 1;
	while (n >= 10)
	{
		n /= 10;
		cpt += 1;
	}
	return (cpt);
}

char		*ft_utoa(unsigned int n)
{
	char	*res;
	int		len;

	len = nbrlen(n);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	while (n >= 10)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	res[len] = n + '0';
	return (res);
}
