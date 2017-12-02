/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 01:52:47 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 00:44:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t		baguettes[BAGUETTE_NBR];

int	main(void)
{
	static t_philo		philos[PHILO_NBR];
	static pthread_t	threads[PHILO_NBR];

	baguettes_init();
	philos_init(philos, threads);
	while (42)
		;
	//some kind of cleanup functions
}
