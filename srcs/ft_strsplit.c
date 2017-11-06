/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:59:38 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/06 20:22:43 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_copy(char const *s, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static size_t	nb_words(char const *s, char c)
{
	size_t	cpt;
	size_t	i;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			cpt++;
		i++;
	}
	return (cpt);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	word;
	size_t	i;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (nb_words(s, c) + 1));
	if (!res)
		return (NULL);
	word = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			res[word++] = ft_copy(s + i, c);
		}
		i++;
	}
	res[word] = NULL;
	return (res);
}
