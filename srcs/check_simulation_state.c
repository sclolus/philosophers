/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation_state.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 00:54:02 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 02:35:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline void	check_simulation_state(t_philo *philos, const time_t *start_time)
{
	uint64_t	i;

	i = 0;
	if (time(NULL) - *start_time >= TIMEOUT)
	{
		printf("%s\n", TIMEOUT_MSG);
		simulation_ended = 1;
		return ;
	}
	while (i < PHILO_NBR)
	{
		if (philos[i].hp == 0)
		{
			philos[i].state = DEAD;
			simulation_ended = 1;
			printf("Simulation terminated because philo: %llu died\n", philos[i].thread_nbr);
			getchar(); // REMOVE THIS
			return ;
		}
		i++;
	}
}
