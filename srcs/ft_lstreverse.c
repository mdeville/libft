/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:57:02 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/10 11:10:41 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **alst)
{
	t_list *prev;
	t_list *curr;
	t_list *tmp;

	if (!alst || !*alst)
		return ;
	curr = *alst;
	prev = NULL;
	while (curr)
	{
		tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	*alst = prev;
}
