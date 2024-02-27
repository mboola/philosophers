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

t_pgrm_data	*convert_input(int argc, char **argv)
{
	t_pgrm_data	*data;
	char			err;

	if (argc < 5 || argc > 6)
		return (NULL);
	data = ft_calloc(sizeof(t_pgrm_data), 1);
	if (data == NULL)
		return (NULL);
	err = 0;
	data->n_philosophers = ft_atoi_err(argv[1], &err);
	data->ms_to_die = ft_atoi_err(argv[2], &err);
	data->ms_to_eat = ft_atoi_err(argv[3], &err);
	data->ms_to_sleep = ft_atoi_err(argv[4], &err);
	data->can_end = 0;
	data->times_to_eat = 0;
	if (argc == 6)
	{
		data->can_end = 1;
		data->times_to_eat = ft_atoi_err(argv[5], &err);
		if (data->times_to_eat < 0)
			err = 1;
	}
	if (err)
		return (clear_data(&data));
	return (data);
}
