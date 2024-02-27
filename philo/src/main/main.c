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
	//main loop
	display_fork(1000000, 1);
	display_eating(1000000, 1);
	display_sleeping(1000000, 1);
	display_thinking(1000000, 1);
	display_died(1000000, 1);
	clear_data(&data);
	return (0);
}
