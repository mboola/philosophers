/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:16:13 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:16:20 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*
*	Library with write function.
*/
# include <unistd.h>

/*
*	Library with malloc and free functions.
*/
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# include "philo_structs.h"
# include "values_limits.h"
# include "error_msg.h"

/*
 *	Functions to initialize the program correctly.
 */
char	init_data(int argc, char **argv, t_dinnertable *dinnertable,
	const char **error_msg);
char	init_control(t_dinnertable *dinnertable, const char **error_msg);
char	init_threads(t_dinnertable *dinnertable, const char **error_msg);

char	destroy_mutexes(int n_mutexs_created, int j, t_control *mutexes);
char	end_threads(t_dinnertable *dinnertable, int n_threads_created);
/*
 *	Functions used when converting input to data the program will use.
 */
int		ft_atoi_err(const char *str, char *err);

/*
 *	Functions used in memory allocation.
 */
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);

/*
 *	Functions used to display data.
 */
int		ft_putstr(int fd, char *str);
int		ft_putchar(int fd, char c);
int		ft_putnbr_long(int fd, unsigned long number);
int		ft_putnbr(int fd, int num);
int		ft_putstr(int fd, char *str);

/*
 *	Functions to display the states of the philosophers.
 */
int		display_fork(long ms, int philosopher, pthread_mutex_t *mutex);
int		display_eating(long ms, int philosopher, pthread_mutex_t *mutex);
int		display_sleeping(long ms, int philosopher, pthread_mutex_t *mutex);
int		display_thinking(long ms, int philosopher, pthread_mutex_t *mutex);
int		display_died(long ms, int philosopher, pthread_mutex_t *mutex);
int		display_state(long ms, int philo, char *state, pthread_mutex_t *mutex);

/*
 *	Actions of philsophers.
 */
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);

void	*philo_funct(void *arg);

/*
 *	Printing an error when starting the program to stdout.
 */
void	print_error(const char *error_msg);

long	get_time();
long	get_curr_time(t_philo *philo);

#endif
