/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:46:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 10:47:05 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	create_mutex(pthread_mutex_t *mutex, int *n_mutexes_created)
{
	if (pthread_mutex_init(mutex, NULL) != MUTEX_CORRECTLY_CREATED)
		return (ERROR);
	(*n_mutexes_created)++;
	return (CORRECT);
}

static char	init_mutexes(t_control *mutexes, int n_philo)
{
	int	n_mutexes_created;
	int	j;

	n_mutexes_created = 0;
	j = 0;
	if (create_mutex(&mutexes->access_to_forks, &n_mutexes_created) == ERROR)
		return (destroy_mutexes(n_mutexes_created, j, mutexes));
	if (create_mutex(&mutexes->limit_access, &n_mutexes_created) == ERROR)
		return (destroy_mutexes(n_mutexes_created, j, mutexes));
	if (create_mutex(&mutexes->update_n_access, &n_mutexes_created) == ERROR)
		return (destroy_mutexes(n_mutexes_created, j, mutexes));
	if (create_mutex(&mutexes->liberate_forks, &n_mutexes_created) == ERROR)
		return (destroy_mutexes(n_mutexes_created, j, mutexes));
	if (create_mutex(&mutexes->print_access, &n_mutexes_created) == ERROR)
		return (destroy_mutexes(n_mutexes_created, j, mutexes));
	if (create_mutex(&mutexes->starved, &n_mutexes_created) == ERROR)
		return (destroy_mutexes(n_mutexes_created, j, mutexes));
	while (j < n_philo)
	{
		if (create_mutex(&(mutexes->forks[j]), &n_mutexes_created) == ERROR)
			return (destroy_mutexes(n_mutexes_created, j, mutexes));
		j++;
	}
	return (CORRECT);
}

/*
 *	What should happen with only one philo?
 *	It must only have one fork (subject says n_forks = n_philo)
 *	Then it must die, it needs at least two forks to eat.
 */
char	init_control(t_dinnertable *dinnertable, const char **error_msg)
{
	dinnertable->control->n_access = 0;
	if (dinnertable->n_philosophers == 1)
		dinnertable->control->max_n_access = 1;
	else
		dinnertable->control->max_n_access = dinnertable->n_philosophers - 1;
	dinnertable->control->forks = ft_calloc(sizeof(pthread_mutex_t), dinnertable->n_philosophers);
	if (dinnertable->control->forks == NULL)
	{
		*error_msg = MALLOC_ERROR;
		return (ERROR);
	}
	if (init_mutexes(dinnertable->control, dinnertable->n_philosophers) == ERROR)
	{
		free(dinnertable->control->forks);
		return (ERROR);
	}
	return (CORRECT);
}
