/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:46:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 10:47:05 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 *	Thread-safe, we do not need to control access.
 */
long	get_time()
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	return ((timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000));
}

long	get_time_diff(t_philo *philo)
{
	return (get_time() - philo->start_time);
}

/*
 *	A philo waits time_to_wait (in ms). If can_die is TRUE, it can die while
 *	waiting.
 */
void	philo_spend_time(t_philo *philo, long time_to_wait, char can_die)
{
	long	time_waiting;

	time_waiting = 0;
	while (time_waiting < time_to_wait)
	{
		usleep(A_MILISECOND);
		if (can_die == TRUE)
		{
			philo->time_till_death--;
			if (philo->time_till_death <= 0)
			{
				display_died(philo, philo->dinnertable->control);
				return ;
			}
		}
		time_waiting++;
	}
}
