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

void	display_fork(t_philo *philo, t_control *control)
{
	pthread_mutex_lock(&(control->starved));
	if (control->end == TRUE)
	{
		pthread_mutex_unlock(&(control->starved));
		return ;
	}
	display_state(philo, FORK_TAKEN_MSG, control);
	pthread_mutex_unlock(&(control->starved));
}

void	display_eating(t_philo *philo, t_control *control)
{
	pthread_mutex_lock(&(control->starved));
	if (control->end == TRUE)
	{
		pthread_mutex_unlock(&(control->starved));
		return ;
	}
	display_state(philo, EAT_MSG, control);
	pthread_mutex_unlock(&(control->starved));
}

void	display_sleeping(t_philo *philo, t_control *control)
{
	pthread_mutex_lock(&(control->starved));
	if (control->end == TRUE)
	{
		pthread_mutex_unlock(&(control->starved));
		return ;
	}
	display_state(philo, SLEEP_MSG, control);
	pthread_mutex_unlock(&(control->starved));
}

void	display_thinking(t_philo *philo, t_control *control)
{
	pthread_mutex_lock(&(control->starved));
	if (control->end == TRUE)
	{
		pthread_mutex_unlock(&(control->starved));
		return ;
	}
	display_state(philo, THINKING_MSG, control);
	pthread_mutex_unlock(&(control->starved));
}

void	display_died(t_philo *philo, t_control *control)
{
	pthread_mutex_lock(&(control->starved));
	if (control->end == FALSE)
	{
		control->end = TRUE;
		display_state(philo, DEATH_MSG, control);
	}
	pthread_mutex_unlock(&(control->starved));
}
