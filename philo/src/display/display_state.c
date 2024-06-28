/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:01:48 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:01:58 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	display_msg(t_philo *philo, const char *state)
{
	ft_putnbr_long(1, get_time_diff(philo));
	ft_putstr(1, ": philosopher ");
	ft_putnbr(1, philo->id);
	ft_putstr(1, state);
}

void	display_state(t_philo *philo, const char *state, t_control *control)
{
	pthread_mutex_lock(&(control->print_access));
	display_msg(philo, state);
	pthread_mutex_unlock(&(control->print_access));
}

void	print_error(const char *error_msg)
{
	ft_putstr(1, (char *) error_msg);
}
