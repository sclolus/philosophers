/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:39:15 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/09 04:23:22 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_page(void *addr)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = addr - ((unsigned long)4095 & (unsigned long)addr);
	while (i < 4096)
	{
		if (ft_isprint(tmp[i]))
			ft_putchar(tmp[i]);
		else
			ft_putchar('.');
		i++;
		if (!(i % 64))
			ft_putchar('\n');
	}
	ft_putchar('\n');
}
