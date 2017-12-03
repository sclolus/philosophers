/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 02:31:02 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 03:22:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophing(void *arg) // return value ?
{
	static const t_f_philo_callback	callbacks[CALLBACK_NBR + 1] =
									{NULL, NULL, &rest_state_callback, NULL};
	t_philo			*philo;

	philo = arg;
	while (42 && philo->state && !simulation_ended)
	{
		if (callbacks[philo->state])
			callbacks[philo->state](philo);
	}
	return (NULL);
}
