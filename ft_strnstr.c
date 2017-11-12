/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 15:15:22 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/20 18:20:49 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lentmp;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && len)
	{
		if (big[i] == little[0])
		{
			j = i;
			lentmp = len;
			while (little[j - i] && little[j - i] == big[j] && lentmp)
			{
				j++;
				lentmp--;
			}
			if (!little[j - i])
				return ((char *)big + i);
		}
		len--;
		i++;
	}
	return (NULL);
}
