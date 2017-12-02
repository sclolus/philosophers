/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baguettes_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 02:07:53 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/02 02:15:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline void baguettes_init(void)
{
	uint64_t	i;

	i = 0;
	while (i < BAGUETTE_NBR)
	{
		if (pthread_mutex_init((pthread_mutex_t*)&baguettes + i, NULL)) /* maybe should get FAST_MUTEX */
			ft_error_exit(1, (char*[]){BAGUETTE_INIT_FAILURE}, EXIT_FAILURE);
		i++;
	}
}
