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

static void	main_loop(t_dinnertable *dinnertable)
{
	dinnertable->control.start = TRUE;
	while (!(dinnertable->end));
}

int	main(int argc, char **argv)
{
	t_dinnertable	dinnertable;
	const char		*error_msg;

	if (init_data(argc, argv, &dinnertable, &error_msg) == ERROR)
	{
		print_error(error_msg);
		return (ERROR_PROGRAM);
	}
	if (init_control(&dinnertable, &error_msg) == ERROR)
	{
		print_error(error_msg);
		return (ERROR_PROGRAM);
	}
	dinnertable->control.start = FALSE;
	dinnertable->control.error_init = FALSE;
	if (init_threads(&dinnertable, &error_msg) == ERROR)
	{
		print_error(error_msg);
		return (ERROR_PROGRAM);
	}
	main_loop(&dinnertable);
	finalize_data(&dinnertable);
	return (0);
}
