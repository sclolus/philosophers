/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_state_callback.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 05:20:46 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 07:35:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int32_t	think_state_callback(t_philo *philo)
{
	time_t		old_time;
	uint64_t	*ownership_ptr;

	time(&old_time);
	ownership_ptr = ownerships + philo->thread_nbr;
	if (ownerships[philo->thread_nbr % BAGUETTE_NBR] < PHILO_NBR)
		ownerships[philo->thread_nbr % BAGUETTE_NBR] = philo->thread_nbr;
	else if (ownerships[(philo->thread_nbr + 1) % BAGUETTE_NBR] < PHILO_NBR)
	{
		ownerships[(philo->thread_nbr + 1) % BAGUETTE_NBR] = philo->thread_nbr;
		ownership_ptr = ownerships + (philo->thread_nbr + 1) % BAGUETTE_NBR;
	}
	else
		return ((philo->state = RESTING));
	while (time(NULL) - old_time >= THINK_T)
	{
		if (*ownership_ptr != philo->thread_nbr)
			break ;
	}
	philo->state = EATING;
	return (0);
}
