/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:46:34 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/15 03:21:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	s1_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen((char*)s1);
	len = s1_len + ft_strlen((char*)s2);
	if (!(str = ft_strnew(len)))
		return (0);
	ft_strcpy(str, s1);
	ft_strcpy(str + s1_len, s2);
	return (str);
}
