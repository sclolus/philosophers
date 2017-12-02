/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:33:53 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/21 02:06:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sus_addr(unsigned long *longword_ptr, const char *s)
{
	char *tmp;

	tmp = (char *)(longword_ptr - 1);
	if (!tmp[0])
		return (tmp - s);
	else if (!tmp[1])
		return (tmp - s + 1);
	else if (!tmp[2])
		return (tmp - s + 2);
	else if (!tmp[3])
		return (tmp - s + 3);
	else if (!tmp[4])
		return (tmp - s + 4);
	else if (!tmp[5])
		return (tmp - s + 5);
	else if (!tmp[6])
		return (tmp - s + 6);
	else
		return (tmp - s + 7);
}

size_t			ft_strlen(const char *s)
{
	unsigned long	*longword_ptr;
	unsigned char	*tmp;
	unsigned long	longword;
	unsigned long	magicbit;
	unsigned long	tester;

	magicbit = (0x7efefefeL << 32) | 0xfefefeffL;
	tester = ~magicbit;
	tmp = (unsigned char*)s;
	while ((unsigned long)tmp & (sizeof(unsigned long) - 1))
	{
		if (!*tmp)
			return ((unsigned char *)tmp - (unsigned char*)s);
		++tmp;
	}
	longword_ptr = (unsigned long*)tmp;
	while (1)
	{
		longword = *longword_ptr++;
		if (((longword + magicbit) ^ ~longword) & tester)
			return (ft_sus_addr(longword_ptr, s));
	}
}
