/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:33:46 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/07 11:17:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = -1;
	if (!s || !f)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen((char*)s) + 1)))
		return (0);
	while (s[++i])
		str[i] = f((unsigned int)i, s[i]);
	str[i] = '\0';
	return (str);
}
