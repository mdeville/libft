/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 15:15:22 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/06 18:11:24 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;

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
	return ((!*needle) ? (char *)haystack : NULL);
}
