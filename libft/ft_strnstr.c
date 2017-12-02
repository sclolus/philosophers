/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:57:20 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/06 17:54:50 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		u;

	i = 0;
	while (big[i] && i < len)
	{
		u = 0;
		while (big[i + u] == little[u] && big[i + u] && i + u < len)
			u++;
		if (!little[u])
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}
