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

t_pgrm_data	*clear_data(t_pgrm_data **data)
{
	if ((*data)->philos != NULL)
		free((*data)->philos);
	if ((*data)->forks != NULL)
		free((*data)->forks);
	free(*data);
	return (NULL);
}
