/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:02:41 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/20 23:28:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*longword_ptr;
	unsigned long	*ptr;
	unsigned int	i;

	i = 0;
	while (i < n % 8)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
	longword_ptr = (unsigned long*)(src + i);
	ptr = (unsigned long*)(dst + i);
	while (i < n)
	{
		*ptr++ = *longword_ptr++;
		i += 8;
	}
	return (dst);
}
