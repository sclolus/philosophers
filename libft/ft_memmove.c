/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:38:00 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/07 19:39:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int		i;

	if (dest > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
