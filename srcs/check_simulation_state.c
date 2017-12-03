/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation_state.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 00:54:02 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 07:21:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_state_str_philo(t_philo_state state)
{
	if (!state)
		return ("FUCKIGN DEAD");
	else if (state == EATING)
		return ("EATING");
	else if (state == RESTING)
		return ("RESTING");
	else
		return ("not thinking definetly");
}

/* inline */ void	check_simulation_state(t_philo *philos, const time_t *start_time
							, time_t *old_time)
{
	uint64_t	i;
	uint64_t	dmg;
	time_t		delta_time;
	time_t		new_time;

	new_time = time(NULL);
	delta_time = new_time - *old_time;
	i = 0;
	if (time(NULL) - *start_time >= TIMEOUT)
	{
		printf("%s\n", TIMEOUT_MSG);
		simulation_ended = 1;
		return ;
	}
	dmg = 0;
	if (delta_time >= 1)
	{
		*old_time = new_time;
		dmg = (uint64_t)(DMG_PER_SEC * delta_time);
	}
	while (i < PHILO_NBR)
	{
		if (philos[i].state != EATING)
			philos[i].hp = (philos[i].hp > dmg) ? philos[i].hp - dmg : 0;
		if (dmg)
			printf("philo_id: %llu, philo_hp: %llu -> %s \n", philos[i].thread_nbr, philos[i].hp, get_state_str_philo(philos[i].state));
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
	if (dmg)
		printf("\n");
}
