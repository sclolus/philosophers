/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:03:01 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/21 01:48:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*tmp;
	unsigned int	len;

	len = ft_strlen(s1);
	if (!(tmp = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strcpy(tmp, (char*)s1);
	tmp[len] = ((char*)s1)[len];
	return (tmp);
}
