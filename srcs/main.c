/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 01:52:47 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 01:03:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t		baguettes[BAGUETTE_NBR];
int32_t				simulation_ended = 0;

int	main(void)
{
	static t_philo		philos[PHILO_NBR];
	static pthread_t	threads[PHILO_NBR];
	static time_t		start_time;

	baguettes_init();
	philos_init(philos, threads);
	time(&start_time);
	while (42)
	{
		check_simulation_state(philos, (const time_t*)&start_time);
		if (simulation_ended)
			break ;
	}
	//some kind of cleanup functions
	return (0);
}
