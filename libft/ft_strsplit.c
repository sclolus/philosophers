/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:15:44 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/07 12:58:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_is_in_str(char c, char *str)
{
	if (*str == c)
		return (1);
	return (0);
}

static int		ft_strlen_char(char *str, char *separators)
{
	int i;

	i = 0;
	while (str[i] && !ft_is_in_str(str[i], separators))
		i++;
	return (i);
}

static int		ft_count_words(char *str, char *separators)
{
	int i;
	int in_a_word;
	int str_nbr;

	i = 0;
	if (!str)
		return (0);
	str_nbr = 0;
	in_a_word = 0;
	while (str[i])
	{
		if (!(ft_is_in_str(str[i], separators)) && !in_a_word)
		{
			in_a_word = 1;
			str_nbr++;
		}
		else if (ft_is_in_str(str[i], separators))
			in_a_word = 0;
		i++;
	}
	return (str_nbr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		str_nbr;
	char	**strs;
	int		strs_len;
	int		cs[3];

	str_nbr = ft_count_words((char*)s, &c);
	cs[0] = 0;
	cs[2] = 0;
	if (!(strs = (char**)malloc(sizeof(char*) * str_nbr + 1)) || !s)
		return (0);
	strs[str_nbr] = 0;
	while (cs[0] < str_nbr)
	{
		cs[1] = 0;
		while (ft_is_in_str(((char*)s)[cs[2]], &c))
			cs[2]++;
		strs_len = ft_strlen_char((char*)s + cs[2], &c);
		if (!(strs[cs[0]] = (char*)malloc(sizeof(char) * strs_len + 1)))
			return (0);
		while (cs[1] < strs_len)
			strs[cs[0]][cs[1]++] = ((char*)s)[cs[2]++];
		strs[cs[0]][cs[1]] = '\0';
		cs[0]++;
	}
	return (strs);
}
