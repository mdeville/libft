/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:20:52 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/08 17:29:11 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist **tmp;

	if (!alst || !*alst || !del)
		return ;
	tmp = &((*alst)->next);
	ft_dlstdel_front(tmp, del);
	ft_dlstdel_back(alst, del);
}
