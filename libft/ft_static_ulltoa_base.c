/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_ulltoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:45:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/28 17:57:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline uint32_t	ft_countnbr(uint64_t nbr, uint32_t base_len)
{
	uint32_t		len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		len++;
		nbr /= base_len;
	}
	return (len);
}

char					*ft_static_ulltoa_base(uint64_t nbr, char *base)
{
	static char		str[65];
	uint32_t		len;
	uint32_t		base_len;
	uint32_t		i;

	base_len = ft_strlen(base);
	len = ft_countnbr(nbr, base_len);
	i = len;
	while (i > 0)
	{
		i--;
		str[i] = base[nbr % base_len];
		nbr /= base_len;
	}
	str[len] = '\0';
	return (str);
}
