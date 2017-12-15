/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:22:25 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/07 11:12:22 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_nbrlen(uintmax_t n, size_t blen)
{
	int cpt;

	cpt = 1;
	while (n >= blen)
	{
		cpt++;
		n /= blen;
	}
	return (cpt);
}

char			*ft_utoa_base(uintmax_t n, const char *base)
{
	char	*res;
	size_t	blen;
	int		nbrlen;

	blen = ft_strlen(base);
	nbrlen = ft_nbrlen(n, blen);
	if (!(res = (char *)malloc(sizeof(char) * (nbrlen + 1))))
		return (NULL);
	res[nbrlen--] = '\0';
	while (n >= blen)
	{
		res[nbrlen--] = base[n % blen];
		n /= blen;
	}
	res[nbrlen] = base[n];
	return (res);
}
