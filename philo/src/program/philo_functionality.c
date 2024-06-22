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

void	*philo_funct(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->dinnertable->error_init == FALSE
		&& philo->dinnertable->start == FALSE);
	philo->start_time = get_time();
	if (philo->dinnertable->error_init == FALSE)
	{
		while (philo->dinnertable->end == FALSE)
		{
			philo_think(philo);
			philo_eat(philo);
			philo_sleep(philo);
		}
	}
	free(philo);
	pthread_exit(0);
}
