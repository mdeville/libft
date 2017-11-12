/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:50:20 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/07 20:31:00 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strndup(char const *s, size_t n)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(s);
	if (n >= len)
		res = (char *)malloc(sizeof(char) * (len + 1));
	if (n < len)
		res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (n && i < len)
	{
		res[i] = s[i];
		i++;
		n--;
	}
	res[i] = '\0';
	return (res);
}
