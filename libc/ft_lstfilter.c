/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:57:32 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/10 14:54:31 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static inline void	ft_trimhead(
							t_list **alst,
							int (*p)(t_list *),
							void (*del)(void *, size_t))
{
	t_list *tmp;

	while (!(*p)(*alst))
	{
		tmp = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(&tmp, del);
	}
}

void				ft_lstfilter(
							t_list **alst,
							int (*p)(t_list *),
							void (*del)(void *, size_t))
{
	t_list *curr;
	t_list *prev;

	if (!alst)
		return ;
	ft_trimhead(alst, p, del);
	prev = (*alst) ? *alst : NULL;
	curr = (*alst) ? (*alst)->next : NULL;
	while (curr)
	{
		if (!(*p)(curr))
		{
			prev->next = curr->next;
			ft_lstdelone(&curr, del);
			curr = prev->next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
