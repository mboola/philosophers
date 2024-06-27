/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:46:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 10:47:05 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	end_threads(t_dinnertable *dinnertable, int n_threads_created)
{
	int	i;

	i = 0;
	while (i < n_threads_created)
	{
		pthread_join(dinnertable->thread_id[i], NULL);
		i++;
	}
	destroy_mutexes(dinnertable->n_philosophers + N_MUTEXES,
		dinnertable->n_philosophers, dinnertable->control);
	free(dinnertable->control->forks);
	return (ERROR);
}

static char	check_destroy(pthread_mutex_t *mutex, int *i)
{
	if (*i == 0)
		return (ERROR);
	pthread_mutex_destroy(mutex);
	(*i)--;
	return (CORRECT);
}

char	destroy_mutexes(int n_mutexs_created, int j, t_control *mutexes)
{
	int	i;

	i = n_mutexs_created;
	if (check_destroy(&(mutexes->access_to_forks), &i) == ERROR)
		return (ERROR);
	if (check_destroy(&(mutexes->limit_access), &i) == ERROR)
		return (ERROR);
	if (check_destroy(&(mutexes->update_n_access), &i) == ERROR)
		return (ERROR);
	if (check_destroy(&(mutexes->liberate_forks), &i) == ERROR)
		return (ERROR);
	if (check_destroy(&(mutexes->print_access), &i) == ERROR)
		return (ERROR);
	if (check_destroy(&(mutexes->starved), &i) == ERROR)
		return (ERROR);
	while (j >= 0)
	{
		if (check_destroy(&(mutexes->forks[j]), &i) == ERROR)
			return (ERROR);
		j--;
	}
	return (ERROR);
}
