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

static int	get_forks(unsigned char id, t_pgrm_data *data)
{
	unsigned char	fork1;
	unsigned char	fork2;
	char			gotten;

	gotten = 0;
	while (!gotten)
	{
		if (pthread_mutex_lock(&(data->forks_mutex)))
			return (0);
		if (id == 0 || id == data->n_philosophers - 1)
		{
			fork1 = 0;
			fork2 = data->n_philosophers - 1;
		}
		else
		{
			fork1 = id;
			fork2 = id + 1;
		}
		if (*(data->forks + fork1) && *(data->forks + fork2))
		{
			*(data->forks + fork1) = 0;
			*(data->forks + fork2) = 0;
			gotten = 1;
		}
		if (pthread_mutex_unlock(&(data->forks_mutex)))
			return (0);
	}
	return (1);
}

static int	release_forks(unsigned char id, t_pgrm_data *data)
{
	unsigned char	fork1;
	unsigned char	fork2;

	if (pthread_mutex_lock(&(data->forks_mutex)))
		return (0);
	if (id == 0 || id == data->n_philosophers - 1)
	{
		fork1 = 0;
		fork2 = data->n_philosophers - 1;
	}
	else
	{
		fork1 = id;
		fork2 = id + 1;
	}
	*(data->forks + fork1) = 1;
	*(data->forks + fork2) = 1;
	if (pthread_mutex_unlock(&(data->forks_mutex)))
		return (0);
	return (1);
}

void	philo_eat(t_philo *philo)
{
	get_forks(philo->id, philo->data);
	display_eating(get_time_diff(philo->data->init_time),
		philo->id, &(philo->data->print_mutex));
	usleep(philo->data->ms_to_eat * 1000);
	release_forks(philo->id, philo->data);
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
