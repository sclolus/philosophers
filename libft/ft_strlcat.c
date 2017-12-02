/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:43:37 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/07 11:47:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		size_dst;
	char	*tmp_src;
	size_t	i;
	int		u;

	u = 0;
	size_dst = ft_strlen(dst);
	i = 0;
	tmp_src = (char *)src;
	while (i < size && dst[i])
		i++;
	if (i == size)
		return (ft_strlen(tmp_src) + i);
	while (i < size - 1)
		dst[i++] = src[u++];
	dst[i] = '\0';
	return (ft_strlen(tmp_src) + size_dst);
}
