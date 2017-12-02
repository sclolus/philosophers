/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:34:34 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/21 02:24:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = ft_strlen(s2);
	n = n > i ? i : n;
	i = ft_strlen(s1);
	ft_strncpy(s1 + i, s2, n);
	s1[i + n] = '\0';
	return (s1);
}
