/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:45:51 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/20 11:13:58 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

#undef MAXARG
#define MAXARG 100

static size_t	get_args(size_t n, va_list *ap, char *bufarg[])
{
	size_t	i;
	size_t	total;
	char	*tmp;

	i = 0;
	total = 0;
	while (i < n && i < MAXARG)
	{
		tmp = va_arg(*ap, char *);
		total += ft_strlen(tmp);
		bufarg[i] = tmp;
		i += 1;
	}
	return (total);
}

char			*ft_strnjoin(size_t n, ...)
{
	size_t	total;
	size_t	i;
	va_list	ap;
	char	*res;
	char	*bufarg[MAXARG];

	va_start(ap, n);
	total = get_args(n, &ap, bufarg);
	va_end(ap);
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	*res = '\0';
	i = 0;
	while (i < n && i < MAXARG)
	{
		ft_strcat(res, bufarg[i]);
		i += 1;
	}
	return (res);
}
