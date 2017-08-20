/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 15:15:22 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/20 15:43:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = i;
			k = 0;
			while (needle[k] && needle[k] == haystack[j])
			{
				j++;
				k++;
			}
			if (!needle[k])
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
