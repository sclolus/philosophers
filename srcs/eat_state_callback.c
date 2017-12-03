/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_state_callback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 02:25:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 03:26:16 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		eat_state_callback(t_philo *philo)
{
	if (pthread_mutex_trylock(pthread_mutex_t*)&baguette[philo->i % PHILO_NBR] != 0)
	{
		philo->state = THINKING;
		return (1);
	}
	if (pthread_mutex_trylock(pthread_mutex_t*)&baguette[(philo->i + 1) % PHILO_NBR] != 0)
	{
		pthread_mutex_unlock((pthread_mutex_t*)&baguette[philo->i % PHILO_NB]);
		philo->state = THINKING;
		return (2);
	}
	philo->hp = MAX_LIFE;
	sec_sleep(EAT_T);
	pthread_mutex_unlock((pthread_mutex_t*)&baguette[philo->i % PHILO_NB]);
	pthread_mutex_unlock((pthread_mutex_t*)&baguette[(philo->i + 1) % PHILO_NB]);
	philo->state = RESTING;
	return (0);
}
