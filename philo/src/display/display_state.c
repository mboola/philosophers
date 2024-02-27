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
int	display_state(long ms, int philo, char *state, pthread_mutex_t *mutex)
{
	char	err;

	if (pthread_mutex_lock(mutex))
		return (0);
	err = 0;
	ft_putnbr_long_err(1, ms, &err);
	if (err)
		return (0);
	ft_putchar_err(1, ' ', &err);
	if (err)
		return (0);
	ft_putnbr_err(1, philo, &err);
	if (err)
		return (0);
	ft_putstr_err(1, state, &err);
	if (err)
		return (0);
	if (pthread_mutex_unlock(mutex))
		return (0);
	return (1);
}
