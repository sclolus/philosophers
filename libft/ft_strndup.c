/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 04:58:30 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/12 07:16:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t len)
{
	char	*tmp;

	if (!(tmp = ft_strnew(len)))
		exit(EXIT_FAILURE);
	ft_memcpy(tmp, str, len);
	return (tmp);
}
