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
#include <stdio.h>

static void	*philosopher_loop(void *arg)
{
	t_pgrm_data *data;

	data = (t_pgrm_data *)arg;
	display_eating(1000000, 1, &(data->print_mutex));
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
	
	if (pthread_mutexattr_init(&attr))                                  
		return (0);
	if (pthread_mutex_init(&(data->print_mutex), &attr))
		return (0);
	return (1);
}

char	init_philosophers(pthread_t *philos, t_pgrm_data *data)
{
	int	i;

	if (!init_mutex(data))
		return (0);
	i = 0;
	while (i < data->n_philosophers)
	{
		if (pthread_create(&philos[i], NULL, philosopher_loop, data))
		{
			//TODO: close all threads
			return (0);
		}
		i++;
	}
	return (1);
}
