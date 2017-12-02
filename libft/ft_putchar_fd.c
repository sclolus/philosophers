/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:05:52 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/07 11:49:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	utf[2];

	if (!ft_isascii((unsigned char)c))
	{
		utf[0] = 0xC0 | ((unsigned char)c >> 6);
		utf[1] = 0x80 | (0x3F & (unsigned char)c);
		write(fd, utf, 2);
	}
	else
		write(fd, &c, 1);
}
