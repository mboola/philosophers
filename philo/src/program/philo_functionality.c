/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functionality.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:46:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 10:47:05 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_loop(t_philo *philo)
{
	t_control	*control;

	control = philo->dinnertable->control;
	while (control->end == FALSE && philo->end == FALSE) //n_times_eat > 0
	{
		philo_think(philo);
		if (control->end == FALSE)
			philo_eat(philo);
		if (control->end == FALSE)
			philo_sleep(philo);
	}
}

void	*philo_funct(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->dinnertable->error_init == FALSE
		&& philo->dinnertable->start == FALSE);
	philo->start_time = get_time();
	if (philo->dinnertable->error_init == FALSE)
		philo_loop(philo);
	free(philo);
	pthread_exit(0);
}
