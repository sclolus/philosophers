/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_put_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:55:22 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/01 19:36:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** Stupid norme
*/

static uint32_t	ft_static_auto_flush(char **str, uint32_t *len
									, char *buf, uint32_t **offset_fd)
{
	uint32_t	count;
	uint32_t	len_tmp;
	uint32_t	offset_tmp;

	count = 0;
	len_tmp = *len;
	offset_tmp = *offset_fd[0];
	while (len_tmp + offset_tmp >= STATIC_BUF_SIZE)
	{
		ft_memcpy(buf + offset_tmp, *str + count, STATIC_BUF_SIZE - offset_tmp);
		write(*offset_fd[1], buf, STATIC_BUF_SIZE);
		count += STATIC_BUF_SIZE;
		len_tmp -= STATIC_BUF_SIZE - offset_tmp;
		*str += STATIC_BUF_SIZE - offset_tmp;
		offset_tmp = 0;
	}
	*len = len_tmp;
	*offset_fd[0] = offset_tmp;
	return (count);
}

uint32_t		ft_static_put_fd(char *str, uint32_t len, uint32_t flags
								, int fd)
{
	static char		buffer[STATIC_BUF_SIZE];
	static uint32_t	offset = 0;
	uint32_t		count;

	count = 0;
	if (!str && flags == STATIC_PUT_FLUSH)
		len = 0;
	else if (!str)
		return (ft_static_put("(null)", 6, STATIC_PUT_FLUSH));
	count += ft_static_auto_flush(&str, &len, buffer, (uint32_t*[]){&offset
				, (uint32_t*)&fd});
	ft_memcpy(buffer + offset, str, len);
	count += len;
	offset += len;
	if (flags == STATIC_PUT_FLUSH)
	{
		write(fd, buffer, offset);
		offset = 0;
	}
	return (count);
}
