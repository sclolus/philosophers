/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_state_callback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 02:25:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 07:30:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int32_t		eat_state_callback(t_philo *philo)
{
	if (pthread_mutex_trylock(baguettes + philo->thread_nbr % BAGUETTE_NBR) != 0)
	{
		philo->state = THINKING;
		return (1);
	}
	if (pthread_mutex_trylock(baguettes + (philo->thread_nbr + 1) % BAGUETTE_NBR) != 0)
	{
		pthread_mutex_unlock(baguettes + philo->thread_nbr % BAGUETTE_NBR);
		philo->state = THINKING;
		return (2);
	}
	ownerships[philo->thread_nbr % BAGUETTE_NBR] = PHILO_NBR + philo->thread_nbr;
	ownerships[(philo->thread_nbr + 1) % BAGUETTE_NBR] = PHILO_NBR + philo->thread_nbr;
	sec_sleep(EAT_T);
	philo->hp = MAX_LIFE + 1;
	ownerships[philo->thread_nbr % BAGUETTE_NBR] = 0;
	ownerships[(philo->thread_nbr + 1) % BAGUETTE_NBR] = 0;
	pthread_mutex_unlock((pthread_mutex_t*)&baguettes[philo->thread_nbr % BAGUETTE_NBR]);
	pthread_mutex_unlock((pthread_mutex_t*)&baguettes[(philo->thread_nbr + 1) % BAGUETTE_NBR]);
	philo->state = RESTING;
	return (0);
}
