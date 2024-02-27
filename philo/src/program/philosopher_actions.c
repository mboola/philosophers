/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:46:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 10:47:05 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	get_forks(unsigned char id, pthread_mutex_t *forks)
{
	//
}

static void	release_forks(unsigned char id, pthread_mutex_t *forks)
{
	
}

void	philo_eat(t_philo *philo)
{
	get_forks(philo->id, philo->data->forks);
	display_eating(get_time_diff(philo->data->init_time),
		philo->id, &(philo->data->print_mutex));
	usleep(philo->data->ms_to_eat * 1000);
	release_forks(philo->id, philo->data->forks);
}

void	philo_sleep(t_philo *philo)
{
	display_sleeping(get_time_diff(philo->data->init_time),
		philo->id, &(philo->data->print_mutex));
	usleep(philo->data->ms_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	display_thinking(get_time_diff(philo->data->init_time),
		philo->id, &(philo->data->print_mutex));
}
