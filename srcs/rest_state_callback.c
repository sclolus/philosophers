/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_state_callback.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 03:02:04 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 03:23:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int32_t	rest_state_callback(t_philo *philo)
{
	philo->state = RESTING;
	sec_sleep(REST_T);
	philo->state = EATING;
	return (0);
}
