/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 22:47:28 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/01 22:29:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_atol(const char *str)
{
	uint64_t		nbr;
	int				is_neg;

	nbr = 0;
	is_neg = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		is_neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		nbr = nbr * 10 + *str++ - '0';
	if (is_neg)
		return (-nbr);
	return (nbr);
}
