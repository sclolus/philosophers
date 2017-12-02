/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:00:57 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/07 11:49:37 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_recursive_del(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
}

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	ft_recursive_del(alst, del);
	*alst = 0;
}
