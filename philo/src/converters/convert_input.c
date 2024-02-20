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

t_program_data	convert_input(int argc, char **argv, char *err)
{
	t_program_data	data;

	if (argc < 5 || argc > 6)
	{
		*err = 1;
		return (data);
	}
	data.n_philosophers = ft_atoi_err(argv[1], err);
	data.n_forks = data.n_philosophers;
	data.time_to_die = ft_atoi_err(argv[2], err);
	data.time_to_eat = ft_atoi_err(argv[3], err);
	data.time_to_sleep = ft_atoi_err(argv[4], err);
	if (argc == 6)
	{
		data.count_eating = 1;
		data.n_times_to_eat = ft_atoi_err(argv[5], err);
		if (data.n_times_to_eat <= 0)
			*err = 1;
	}
	else
	{
		data.count_eating = 0;
		data.n_times_to_eat = 0;
	}
	return (data);
}
