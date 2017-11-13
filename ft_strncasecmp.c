/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:57:49 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/13 14:29:12 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	int					result;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while ((result = ft_tolower(*p1) - ft_tolower(*p2++)) == 0 && n--)
		if (*p1++ == '\0')
			break ;
	return ((n == 0) ? 0 : result);
}
