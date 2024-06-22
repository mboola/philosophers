/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_to_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:01:48 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:01:58 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "display_msg.h"

int	display_fork(long ms, int philo_id, pthread_mutex_t *mutex)
{
	return (display_state(ms, philo_id, FORK_TAKEN_MSG, mutex));
}

int	display_eating(long ms, int philo_id, pthread_mutex_t *mutex)
{
	return (display_state(ms, philo_id, EAT_MSG, mutex));
}

int	display_sleeping(long ms, int philo_id, pthread_mutex_t *mutex)
{
	return (display_state(ms, philo_id, SLEEP_MSG, mutex));
}

int	display_thinking(long ms, int philo_id, pthread_mutex_t *mutex)
{
	return (display_state(ms, philo_id, THINKING_MSG, mutex));
}

int	display_died(long ms, int philo_id, pthread_mutex_t *mutex)
{
	return (display_state(ms, philo_id, DEATH_MSG, mutex));
}
