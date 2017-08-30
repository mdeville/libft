/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:06:14 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/29 22:35:57 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = tmp;
	}
}
