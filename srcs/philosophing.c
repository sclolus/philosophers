/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 02:31:02 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 00:49:41 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	time_count(t_philo *philo, time_t *oldtime)
{
	time_t		newtime;
	time_t		delta_time;
	uint64_t	dmg;

	newtime = time(NULL);
	delta_time = newtime - *oldtime;
	if (delta_time >= 1)
	{
		*oldtime = newtime;
		dmg = (uint64_t)(DMG_PER_SEC * delta_time);
		philo->hp = (philo->hp > dmg) ? philo->hp - dmg : 0;
	}
}

void	*philosophing(void *arg) // return value ?
{
	static time_t	oldtime;
	t_philo			*philo;

	philo = arg;
	oldtime = time(NULL);

	while (42)
	{
		printf("test\n");
		time_count(philo, &oldtime);
		if (!philo->hp)
			return (NULL);
	}
}
