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

//probably use a mutex here
int	display_state(long ms, int philo_id, char *state, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	ft_putnbr_long(1, ms);
	ft_putstr(1, ": philosopher ");
	ft_putnbr(1, philo_id);
	ft_putstr(1, state);
	pthread_mutex_unlock(mutex);
	return (1);
}

void	print_error(const char *error_msg)
{
	ft_putstr(1, (char *) error_msg);
}
