/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 20:48:46 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/20 21:25:36 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int		res;
	int		neg;

	res = 0;
	neg = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == ' ')
		nptr++;
	neg = (*nptr == '-') ? -1 : 1;
	nptr = (neg == -1 || *nptr == '+') ? nptr + 1: nptr;
	while (*nptr >= '0' && *nptr <= '9')
		res = res * 10  + (*nptr++ - '0');
	return (res * neg);
}
