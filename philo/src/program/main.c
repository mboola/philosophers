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

int	main(int argc, char **argv)
{
	t_pgrm_data	*data;

	data = convert_input(argc, argv);
	if (data == NULL)
	{
		ft_putstr(1, "Input incorrect.\n");
		return (0);
	}
	data->philos = ft_calloc(sizeof(pthread_t), data->n_philosophers);
	if (data->philos == NULL)
	{
		clear_data(&data);
		return (0);
	}
	if (!init_philosophers(data->philos, data))
	{
		clear_data(&data);
		return (0);
	}
	wait_philosophers(data->philos, data->n_philosophers);
	clear_data(&data);
	return (0);
}
