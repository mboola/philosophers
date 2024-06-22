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
	display_thinking(get_curr_time(philo), philo->id,
		&(philo->dinnertable->control.print_access));
}

static void	access_forks(t_control *mutexes)
{
	pthread_mutex_lock(&(mutexes->access_to_forks));
	if (mutexes->n_access == mutexes->max_n_access - 1)
		pthread_mutex_lock(&(mutexes->limit_access));
	pthread_mutex_lock(&(mutexes->update_n_access));
	mutexes->n_access++;
	pthread_mutex_unlock(&(mutexes->update_n_access));
	pthread_mutex_unlock(&(mutexes->access_to_forks));
}

static void	liberate_forks(t_control *mutexes)
{
	pthread_mutex_lock(&(mutexes->liberate_forks));
	if (mutexes->n_access == mutexes->max_n_access - 1)
		pthread_mutex_unlock(&(mutexes->limit_access));
	pthread_mutex_lock(&(mutexes->update_n_access));
	mutexes->n_access--;
	pthread_mutex_unlock(&(mutexes->update_n_access));
	pthread_mutex_unlock(&(mutexes->liberate_forks));
}

void	philo_eat(t_philo *philo)
{
	t_control	*control;

	control = &(philo->dinnertable->control);
	access_forks(control);
	pthread_mutex_lock(&(control->forks[philo->id]));
	display_fork(get_curr_time(philo), philo->id,
		&(philo->dinnertable->control.print_access));
	pthread_mutex_lock(
		&(control->forks[(philo->id + 1) % philo->dinnertable->n_philosophers]));
	display_fork(get_curr_time(philo), philo->id,
		&(philo->dinnertable->control.print_access));
	display_eating(get_curr_time(philo), philo->id,
		&(philo->dinnertable->control.print_access));
	usleep(philo->dinnertable->data.ms_to_eat);
	pthread_mutex_unlock(&(control->forks[philo->id]));
	pthread_mutex_unlock(
		&(control->forks[(philo->id + 1) % philo->dinnertable->n_philosophers]));
	liberate_forks(control);
}

void	philo_sleep(t_philo *philo)
{
	display_sleeping(get_curr_time(philo), philo->id,
		&(philo->dinnertable->control.print_access));
	usleep(philo->dinnertable->data.ms_to_sleep);
}
