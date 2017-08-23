/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:10:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/23 21:08:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa(int n)
{
	int		power;
	int		i;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = (char *)malloc(sizeof(char) * 12);
	if (!res)
		return (NULL);
	res[0] = (n < 0) ? '-' : 0;
	i = (res[0] == '-') ? 1 : 0;
	n = (res[0] == '-') ? -n : n;
	power = 1;
	while (n / power >= 10)
		power *= 10;
	while (n >= 10)
	{
		res[i++] = n / 10 + '0';
		n %= power;
		power /= 10;
	}
	res[i++] = n + '0';
	res[i] = '\0';
	return (res);
}
