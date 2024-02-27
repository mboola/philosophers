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

static void	*philosopher_loop(void *arg)
{
	t_philo			*philo;
	unsigned char	n;

	n = 0;
	philo = (t_philo *)arg;
	while (n < 3)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		n++;
	}
	pthread_exit(NULL);
}

void	wait_philosophers(pthread_t *philos, char n_philosophers)
{
	unsigned char	i;

	i = 0;
	while (i < n_philosophers)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
}

static char	init_mutex(t_pgrm_data *data)
{
	pthread_mutexattr_t	attr;

	data->forks = ft_calloc(sizeof(char), data->n_philosophers);
	if (data->forks == NULL)
		return (0);
	ft_memset(data->forks, 1, data->n_philosophers);
	if (pthread_mutexattr_init(&attr))                                  
		return (0);
	if (pthread_mutex_init(&(data->print_mutex), &attr))
		return (0);
	if (pthread_mutex_init(&(data->forks_mutex), &attr))
		return (0);
	return (1);
}

char	init_philosophers(pthread_t *philos_id, t_pgrm_data *data)
{
	unsigned char	i;
	t_philo			*philo;

	if (!init_mutex(data))
		return (0);
	i = 0;
	philo = ft_calloc(sizeof(t_philo), data->n_philosophers);
	if (philo == NULL)
		return (0);
	data->init_time = get_time();
	while (i < data->n_philosophers)
	{
		philo[i].data = data;
		philo[i].id = i;
		if (pthread_create(&philos_id[i], NULL, philosopher_loop, &philo[i]))
		{
			//TODO: close all threads
			return (0);
		}
		i++;
	}
	return (1);
}
