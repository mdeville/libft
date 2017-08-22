/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:28:25 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/22 15:33:44 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	begin;
	unsigned int	end;
	int				has_begun;

	i = 0;
	begin = 0;
	end = 0;
	has_begun = 0;
	while (s[i])
	{
		if (!has_begun && !IS_WS(s[i]))
		{
			begin = i;
			has_begun = 1;
		}
		else if (has_begun && IS_WS(s[i]) && !IS_WS(s[i - 1]))
			end = i;
		i++;
	}
	if (end == 0)
		return (ft_strsub(s, begin, ft_strlen(s + begin)));
	else
		return (ft_strsub(s, begin, end - begin));
}
