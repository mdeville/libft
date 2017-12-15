/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:28:25 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/07 17:33:31 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trimbegin(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && IS_WS(s[i]))
		i++;
	return (i);
}

static size_t	ft_trimend(char const *s)
{
	size_t	i;

	if (!*s)
		return (0);
	i = ft_strlen(s) - 1;
	while (i > 0 && IS_WS(s[i]))
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;

	if (!s)
		return (NULL);
	begin = ft_trimbegin(s);
	end = ft_trimend(s);
	if (end < begin)
		return (ft_strdup(""));
	return (ft_strsub(s, begin, end - begin + 1));
}
