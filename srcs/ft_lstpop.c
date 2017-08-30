/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:23:53 by mdeville          #+#    #+#             */
/*   Updated: 2017/08/31 01:01:56 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_lstpop(t_list **lst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	void	*content;

	if (!lst || !*lst)
		return (NULL);
	content = (void *)malloc((*lst)->content_size);
	if (!content)
		return (NULL);
	ft_memcpy(content, (*lst)->content, (*lst)->content_size);
	tmp = *lst;
	*lst = (*lst)->next;
	(*del)(tmp->content, tmp->content_size);
	free(tmp);
	return (content);
}
