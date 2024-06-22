/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:46:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 10:47:05 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philo	*create_philo(t_dinnertable *dinnertable, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->id = id;
	philo->dinnertable = dinnertable;
	return (philo);
}

char	init_threads(t_dinnertable *dinnertable, const char **error_msg)
{
	t_philo	*philo;
	int	i;

	i = 0;
	while (i < dinnertable->n_philosophers)
	{
		philo = create_philo(dinnertable, i);
		if (philo == NULL)
		{
			*error_msg = MALLOC_ERROR;
			dinnertable->error_init = TRUE;
			return (end_threads(dinnertable, i));
		}
		if (pthread_create(&(dinnertable->thread_id[i]), NULL, philo_funct,
			(void *)philo) != THREAD_CORRECTLY_CREATED)
		{
			*error_msg = THREAD_CREATION_ERROR;
			dinnertable->error_init = TRUE;
			return (end_threads(dinnertable, i));
		}
		i++;
	}
	return (CORRECT);
}
