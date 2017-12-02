/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_string_concat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 01:19:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/18 18:40:58 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	*ft_t_string_concat(t_string *string, char *str)
{
	uint64_t	total_len;
	uint64_t	str_len;

	if (!str || !string)
		return (NULL);
	str_len = ft_strlen(str);
	total_len = string->len + str_len;
	if (total_len >= string->capacity)
	{
		ft_t_string_expand(string);
		return (ft_t_string_concat(string, str));
	}
	else
	{
		ft_memcpy(string->string + string->len, str, str_len);
		string->len = total_len;
		string->string[string->len] = '\0';
	}
	return (string);
}
