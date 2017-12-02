/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:18:10 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/21 02:25:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long	*longword_ptr;
	unsigned long	*longword_dst;
	unsigned int	i;
	unsigned int	n;

	n = ft_strlen(src);
	n = n > len ? len : n;
	i = 0;
	while (src[i] && i < n % 8)
	{
		dst[i] = src[i];
		i++;
	}
	longword_ptr = (unsigned long*)(src + i);
	longword_dst = (unsigned long*)(dst + i);
	while (i < n)
	{
		*longword_dst++ = *longword_ptr++;
		i += 8;
	}
	while (i < len)
		dst[i++] = 0;
	return (dst);
}
