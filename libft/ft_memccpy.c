/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:12:37 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/04 12:14:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp_dst;
	unsigned char		*tmp_src;
	size_t				i;

	i = 0;
	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if ((unsigned char)c == tmp_src[i])
			return ((void*)tmp_dst + i + 1);
		i++;
	}
	return (NULL);
}
