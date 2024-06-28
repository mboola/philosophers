/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:01:48 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:01:58 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_think(t_philo *philo)
{
	display_thinking(philo, philo->dinnertable->control);
}

static void	access_forks(t_control *mutexes)
{
	pthread_mutex_lock(&(mutexes->access_to_forks));
	pthread_mutex_lock(&(mutexes->update_n_access));
	if (mutexes->n_access == mutexes->max_n_access - 1)
	{
		pthread_mutex_unlock(&(mutexes->update_n_access));
		pthread_mutex_lock(&(mutexes->limit_access));
		pthread_mutex_lock(&(mutexes->update_n_access));
	}
	mutexes->n_access++;
	pthread_mutex_unlock(&(mutexes->update_n_access));
	pthread_mutex_unlock(&(mutexes->access_to_forks));
}

static void	liberate_forks(t_control *mutexes)
{
	pthread_mutex_lock(&(mutexes->liberate_forks));
	pthread_mutex_lock(&(mutexes->update_n_access));
	if (mutexes->n_access == mutexes->max_n_access - 1)
		pthread_mutex_unlock(&(mutexes->limit_access));
	mutexes->n_access--;
	pthread_mutex_unlock(&(mutexes->update_n_access));
	pthread_mutex_unlock(&(mutexes->liberate_forks));
}

void	philo_eat(t_philo *philo)
{
	t_control	*control;
	//long		enter_time;

	control = philo->dinnertable->control;
	//enter_time = get_time();
	access_forks(control);
	pthread_mutex_lock(&(control->forks[philo->id]));
	//philo->time_till_death = philo->time_till_death
	display_fork(philo, philo->dinnertable->control);
	pthread_mutex_lock(
		&(control->forks[(philo->id + 1) % philo->dinnertable->n_philosophers]));
	display_fork(philo, philo->dinnertable->control);
	display_eating(philo, philo->dinnertable->control);
	philo_spend_time(philo, philo->dinnertable->data.ms_to_eat, FALSE);
	//philo->time_till_death = philo->dinnertable->data.ms_to_die;
	pthread_mutex_unlock(&(control->forks[philo->id]));
	pthread_mutex_unlock(
		&(control->forks[(philo->id + 1) % philo->dinnertable->n_philosophers]));
	liberate_forks(control);
}

void	philo_sleep(t_philo *philo)
{
	display_sleeping(philo, philo->dinnertable->control);
	philo_spend_time(philo, philo->dinnertable->data.ms_to_sleep, TRUE);
}
