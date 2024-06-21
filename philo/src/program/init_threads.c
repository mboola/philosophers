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

char	init_threads(t_dinnertable *dinnertable, char **error_msg)
{
	int	i;

	i = 0;
	while (i < dinnertable->data.n_philosophers)
	{
		if (pthread_create(dinnertable->thread_id[i], NULL, philo_funct,
			(void *) dinnertable) != THREAD_CORRECTLY_CREATED)
			{
				*error_msg = THREAD_CREATION_ERROR;
				return (end_threads(dinnertable, i));
			}
		i++;
	}
	return (CORRECT);
}
