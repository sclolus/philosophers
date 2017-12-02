/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:51:46 by sclolus           #+#    #+#             */
/*   Updated: 2017/03/03 04:18:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*mem;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(mem = ft_memalloc(content_size)))
		{
			free(new);
			return (0);
		}
		ft_memcpy(mem, (void*)content, content_size);
		new->content = mem;
		new->content_size = content_size;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
