/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 02:18:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 00:56:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline void	philos_init(t_philo *philos, pthread_t *threads)
{
	uint64_t	i;

	i = 0;
	while (i < PHILO_NBR)
	{
		philos[i].hp = MAX_LIFE;
		philos[i].state = EATING;
		philos[i].thread_nbr = i;
		if (pthread_create(threads + i, NULL, &philosophing, philos + i))
			ft_error_exit(1, (char*[]){THREAD_INIT_FAILURE}, EXIT_FAILURE);
		i++;
	}
}
