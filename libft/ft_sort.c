/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:08:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/12 20:27:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap(int64_t *a, int64_t *b)
{
	int64_t	tmp;

	if (a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

static uint32_t	ft_partitioning(int64_t *tab, uint32_t start
								, uint32_t last, uint32_t pivot)
{
	uint32_t	i;
	uint32_t	u;

	ft_swap(tab + last, tab + pivot);
	i = start;
	u = start;
	while (i < last)
	{
		if (tab[i] < tab[last])
			ft_swap(tab + i, tab + u++);
		i++;
	}
	ft_swap(tab + last, tab + u);
	return (u);
}

static void		ft_quicksort(int64_t *tab, uint32_t start, uint32_t last)
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

void			ft_sort(int64_t *tab, uint32_t len)
{
	ft_quicksort(tab, 0, len - 1);
	return ;
}
