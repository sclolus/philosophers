/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:56:39 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/21 00:11:08 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sus_diff(unsigned char *s1, unsigned char *s2)
{
	if (s1[0] != s2[0])
		return (s1[0] - s2[0]);
	else if (s1[1] != s2[1])
		return (s1[1] - s2[1]);
	else if (s1[2] != s2[2])
		return (s1[2] - s2[2]);
	else if (s1[3] != s2[3])
		return (s1[3] - s2[3]);
	else if (s1[4] != s2[4])
		return (s1[4] - s2[4]);
	else if (s1[5] != s2[5])
		return (s1[5] - s2[5]);
	else if (s1[6] != s2[6])
		return (s1[6] - s2[6]);
	else
		return (s1[7] - s2[7]);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;
	unsigned long	*longword_ptr;
	unsigned int	i;

	i = 0;
	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	while (i < n % 8)
	{
		if (tmp_s1[i] != tmp_s2[i])
			return (tmp_s1[i] - tmp_s2[i]);
		i++;
	}
	longword_ptr = (unsigned long*)(tmp_s2 + i);
	while (i < n)
	{
		if (*((unsigned long*)(tmp_s1 + i)) != *longword_ptr++)
			return (ft_sus_diff(tmp_s1, tmp_s2));
		i += 8;
	}
	return (0);
}
