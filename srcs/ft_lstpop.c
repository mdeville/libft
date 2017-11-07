/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:27:57 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/07 18:45:25 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_lstpop(t_list **alst, size_t *content_size)
{
	void	*res;
	t_list	*next;

	if (!alst || !*alst)
		return (NULL);
	res = (*alst)->content;
	if (content_size)
		*content_size = (*alst)->content_size;
	next = (*alst)->next;
	free(*alst);
	*alst = next;
	return (res);
}
