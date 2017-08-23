/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:59:38 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/23 21:30:49 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_copy(char const *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	nb_words(char const *s, char c)
{
	int		nb_words;
	int		i;

	nb_words = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			nb_words++;
		i++;
	}
	return (nb_words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		word;
	int		i;

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
