/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 10:51:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/01 22:27:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static uint32_t	ft_static_auto_flush(char **str, uint32_t *len
									, char *buf, uint32_t *offset)
{
	uint32_t	count;
	uint32_t	len_tmp;
	uint32_t	offset_tmp;

	count = 0;
	len_tmp = *len;
	offset_tmp = *offset;
	while (len_tmp + offset_tmp >= STATIC_BUF_SIZE)
	{
		ft_memcpy(buf + offset_tmp, *str + count, STATIC_BUF_SIZE - offset_tmp);
		write(1, buf, STATIC_BUF_SIZE);
		count += STATIC_BUF_SIZE;
		len_tmp -= STATIC_BUF_SIZE - offset_tmp;
		*str += STATIC_BUF_SIZE - offset_tmp;
		offset_tmp = 0;
	}
	*len = len_tmp;
	*offset = offset_tmp;
	return (count);
}

uint32_t		ft_static_put(char *str, uint32_t len, uint32_t flags)
{
	static char		buffer[STATIC_BUF_SIZE];
	static uint32_t	offset = 0;
	uint32_t		count;

	count = 0;
	if (!str && flags == STATIC_PUT_FLUSH)
		len = 0;
	else if (!str)
		return (ft_static_put("(null)", 6, STATIC_PUT_FLUSH));
	count += ft_static_auto_flush(&str, &len, buffer, &offset);
	ft_memcpy(buffer + offset, str, len);
	count += len;
	offset += len;
	if (flags == STATIC_PUT_FLUSH)
	{
		write(1, buffer, offset);
		offset = 0;
	}
	return (count);
}
