/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:28:25 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/08 14:55:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trimbegin(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static size_t	ft_trimend(char const *s, char c)
{
	size_t	i;

	if (!*s)
		return (0);
	i = ft_strlen(s) - 1;
	while (i > 0 && s[i] == c)
		i--;
	return (i);
}

char			*ft_strtrimc(char const *s, char c)
{
	size_t	begin;
	size_t	end;

	if (!s)
		return (NULL);
	begin = ft_trimbegin(s, c);
	end = ft_trimend(s, c);
	if (end < begin)
		return (ft_strdup(""));
	return (ft_strsub(s, begin, end - begin + 1));
}
