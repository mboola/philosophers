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
	t_program_data	data;
	char			err;

	err = 0;
	data = convert_input(argc, argv, &err);
	if (err)
	{
		err = 0;
		ft_putstr_err(1, "Input incorrect.\n", &err);
		return (0);
	}
	ft_putstr_err(1, "Input correct.\n", &err);
	display_fork(1000000, 1);
	display_eating(1000000, 1);
	display_sleeping(1000000, 1);
	display_thinking(1000000, 1);
	display_died(1000000, 1);
	return (0);
}
