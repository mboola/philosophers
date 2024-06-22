/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:46:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 10:47:05 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static void finalize_data(t_dinnertable *dinnertable)
{
	end_threads(dinnertable, dinnertable->n_philosophers);
	//something more?
}

static void	main_loop(t_dinnertable *dinnertable)
{
	//ft_putstr(1, "Max access :");
	//ft_putnbr(1, dinnertable->control.max_n_access);
	//ft_putstr(1, "\n");
	dinnertable->start = TRUE;
	while (dinnertable->end == FALSE);
}

int	main(int argc, char **argv)
{
	t_dinnertable	dinnertable;
	const char		*error_msg;

	if (init_data(argc, argv, &dinnertable, (&error_msg)) == ERROR)
	{
		print_error(error_msg);
		return (ERROR_PROGRAM);
	}
	if (init_control(&dinnertable, (const char **) (void *) (&error_msg)) == ERROR)
	{
		print_error(error_msg);
		return (ERROR_PROGRAM);
	}
	dinnertable.start = FALSE;
	dinnertable.error_init = FALSE;
	dinnertable.end = FALSE;
	if (init_threads(&dinnertable, (const char **) (void *) (&error_msg)) == ERROR)
	{
		print_error(error_msg);
		return (ERROR_PROGRAM);
	}
	main_loop(&dinnertable);
	finalize_data(&dinnertable);
	return (0);
}
