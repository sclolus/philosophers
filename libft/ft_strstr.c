/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:13:08 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/06 17:43:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	u;

	i = 0;
	while (big[i])
	{
		u = 0;
		while (big[i + u] == little[u] && big[i + u])
			u++;
		if (!little[u])
			return ((char*)big + i);
		i++;
	}
	if (!ft_strlen((char*)big) && !(ft_strlen((char*)little)))
		return ((char *)big);
	return (NULL);
}
