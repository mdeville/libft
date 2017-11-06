/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:28:25 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/06 21:48:30 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static size_t	ft_trimbegin(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && IS_WS(s[i]))
		i++;
	return i;
}

static size_t	ft_trimend(char const *s)
{
	size_t	i;

	i = ft_strlen(s);
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
	return (ft_strsub(s, begin, end - begin));
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ft_putstr(ft_strtrim(argv[1]));
}
