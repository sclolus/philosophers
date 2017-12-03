/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 01:52:04 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/03 02:36:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This philosophing simulator is distributed ``as is`` but
** WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** The trollness of this code is not BY ANY MEANS an example of the authors'
** coding abilities, and is highly encouraged by the subject of this project.
** VIEWERS' DISCRETION IS ADVISED
*/

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <stdio.h>//
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <pthread.h>

# define MAX_LIFE 10
# define EAT_T 1
# define REST_T 1
# define THINK_T 1
# define TIMEOUT 3
# define TIMEOUT_MSG "Now, it is time... To DAAAAAAAANCE!!!"
# define DMG_PER_SEC 1L
# define PHILO_NBR 7
# define BAGUETTE_NBR 7

typedef enum	e_philo_state
{
	DEAD = 0,
	EATING,
	RESTING,
	THINKING,
}				t_philo_state;

extern pthread_mutex_t		baguettes[7];
extern int32_t				simulation_ended;

typedef struct	s_philo
{
	uint64_t		hp; // health_point
	uint64_t		thread_nbr;
	t_philo_state	state;
	uint8_t			__pad[4];
}				t_philo;

/*
** Initialization
*/

void	baguettes_init(void);
void	philos_init(t_philo *philos, pthread_t *threads);

/*
** Philosophers' routine
*/

void	*philosophing(void *philo); // return value ?

/*
** Master thread routines
*/

void	check_simulation_state(t_philo *philos, const time_t *start_time);

/*
** Error handling
*/

# define BAGUETTE_INIT_FAILURE "pthread_mutex_init() failed"
# define THREAD_INIT_FAILURE "pthread_create() failed"

#endif
