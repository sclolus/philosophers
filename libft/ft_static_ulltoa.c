/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_ulltoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 23:08:09 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/28 17:46:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline uint32_t	ft_countnbr(uint64_t nbr)
{
	uint32_t		len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static int				ft_putnbr_base(uint64_t value, char *base
									, char *str, int i)
{
	uint64_t		nb;
	uint64_t		tmp;

	nb = value;
	tmp = nb;
	if (tmp > 9)
	{
		i = ft_putnbr_base(nb / 10, base, str, i);
		return (ft_putnbr_base(nb % 10, base, str, i));
	}
	else
	{
		str[i++] = base[nb];
		return (i);
	}
}

char					*ft_static_ulltoa(uint64_t nbr)
{
	static char		str[sizeof("18446744073709551615")];
	uint32_t		len;

	len = ft_countnbr(nbr);
	ft_putnbr_base(nbr, "0123456789", str, 0);
	str[len] = '\0';
	return (str);
}
