/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:11:29 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/12 20:09:50 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist	*ft_dlstnew(char const *content, size_t content_size)
{
	t_dlist	*new_elem;

	new_elem = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new_elem)
		return (NULL);
	new_elem->content = (content) ? malloc(content_size) : NULL;
	if (content && !new_elem->content)
	{
		free(new_elem);
		return (NULL);
	}
	if (content)
		ft_memcpy(new_elem->content, content, content_size);
	new_elem->content_size = (content) ? content_size : 0;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}
