/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:16:13 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:16:20 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

# include "values_limits.h"

typedef struct s_data
{
	int		ms_to_die;
	int		ms_to_eat;
	int		ms_to_sleep;
	char	can_end;
	int		times_to_eat;
}	t_data;

typedef struct s_control
{
	int				n_access;
	int				max_n_access;
	char			end;
	pthread_mutex_t	access_to_forks;
	pthread_mutex_t	limit_access;
	pthread_mutex_t	update_n_access;
	pthread_mutex_t	liberate_forks;
	pthread_mutex_t	print_access;
	pthread_mutex_t	starved;
	pthread_mutex_t	*forks;
}	t_control;

typedef struct s_dinnertable
{
	char		error_init;
	char		start;
	int			n_philosophers;
	pthread_t	philo_id[MAX_THREADS];
	t_data		data;
	t_control	*control;
}	t_dinnertable;

typedef struct s_philo
{
	char			end;
	int				id;
	int				meals_remaining;
	long			start_time;
	long			time_till_death;
	t_dinnertable	*dinnertable;
}	t_philo;

#endif
