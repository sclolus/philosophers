/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:25:22 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/12 20:31:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap(char **a, char **b)
{
	char	*tmp;

	if (a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

static uint32_t	ft_partitioning(char **tab, uint32_t start
								, uint32_t last, uint32_t pivot)
{
	uint32_t	i;
	uint32_t	u;

	ft_swap(tab + last, tab + pivot);
	i = start;
	u = start;
	while (i < last)
	{
		if (ft_strcmp(tab[i], tab[last]) < 0)
			ft_swap(tab + i, tab + u++);
		i++;
	}
	ft_swap(tab + last, tab + u);
	return (u);
}

static void		ft_quicksort(char **tab, uint32_t start, uint32_t last)
{
	uint32_t	pivot;

	if (start < last)
	{
		pivot = (ft_random() % (last - start + 1)) + start;
		pivot = ft_partitioning(tab, start, last, pivot);
		if (pivot > 0)
			ft_quicksort(tab, start, pivot - 1);
		ft_quicksort(tab, pivot + 1, last);
	}
}

void			ft_sort_strings(char **strings, uint32_t n)
{
	if (n < 2 || !strings)
		return ;
	ft_quicksort(strings, 0, n - 1);
	return ;
}
