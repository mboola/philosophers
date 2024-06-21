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
char	init_control(t_dinnertable *dinnertable, char **error_msg)
{
	t_control	mutexes;
	int			n_philo;

	n_philo = dinnertable->data.n_philosophers;
	mutexes.n_access = 0;
	if (n_philo == 1)
		mutexes.max_n_acces = 1;
	else
		mutexes.max_n_acces = n_philo - 1;
	mutexes.forks = ft_calloc(sizeof(pthread_mutex_t) * n_philo);
	if (mutexes.forks == NULL)
	{
		*error_msg = MALLOC_ERROR;
		return (ERROR);
	}
	if (init_mutexes(&mutexes, n_philo) == ERROR)
	{
		free(mutexes.forks);
		return (ERROR);
	}
	dinnertable->control = mutexes;
	return (CORRECT);
}