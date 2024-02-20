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

int	display_fork(long ms, int philosopher)
{
	return (display_state(ms, philosopher, " has taken a fork\n"));
}

int	display_eating(long ms, int philosopher)
{
	return (display_state(ms, philosopher, " is eating\n"));
}

int	display_sleeping(long ms, int philosopher)
{
	return (display_state(ms, philosopher, " is sleeping\n"));
}

int	display_thinking(long ms, int philosopher)
{
	return (display_state(ms, philosopher, " is thinking\n"));
}

int	display_died(long ms, int philosopher)
{
	return (display_state(ms, philosopher, " died\n"));
}
