/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:46:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 10:47:05 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	convert_arg(const char *arg, int *num, int min,
	const char **error_msg)
{
	char	err;

	err = 0;
	*num = ft_atoi_err(arg, &err);
	if (err)
	{
		*error_msg = MAX_INT_OVERFLOW;
		return (ERROR);
	}
	if (*num < min)
	{
		*error_msg = VALUE_INFERIOR_MIN;
		return (ERROR);
	}
	return (CORRECT);
}

static char	init_args(int argc, char **argv, t_dinnertable *dinnertable,
	const char **error_msg)
{
	if (convert_arg(argv[1], &(dinnertable->n_philosophers), 1, error_msg) == ERROR)
		return (ERROR);
	if (convert_arg(argv[2], &(dinnertable->data.ms_to_die), 0, error_msg) == ERROR)
		return (ERROR);
	if (convert_arg(argv[3], &(dinnertable->data.ms_to_eat), 0, error_msg) == ERROR)
		return (ERROR);
	if (convert_arg(argv[4], &(dinnertable->data.ms_to_sleep), 0, error_msg) == ERROR)
		return (ERROR);
	if (argc == 6)
	{
		dinnertable->data.can_end = 1;
		if (convert_arg(argv[5], &(dinnertable->data.times_to_eat), 0, error_msg) == ERROR)
			return (ERROR);
	}
	else
	{
		dinnertable->data.can_end = 0;
		dinnertable->data.times_to_eat = 0;
	}
	return (CORRECT);
}

char	init_data(int argc, char **argv, t_dinnertable *dinnertable,
	const char **error_msg)
{
	if (argc < 5 || argc > 6)
	{
		*error_msg = BAD_PARAMS;
		return (ERROR);
	}
	if (init_args(argc, argv, dinnertable, error_msg) == ERROR)
		return (ERROR);
	if (dinnertable->n_philosophers > MAX_THREADS)
	{
		*error_msg = MAX_THREADS_ERROR;
		return (ERROR);
	}
	return (CORRECT);
}
