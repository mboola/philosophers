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

# ifndef DEC_BASE
#  define DEC_BASE "0123456789"
# endif

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

/*
 *	Functions used when converting input to data the program will use.
 */
t_pgrm_data	*convert_input(int argc, char **argv);
suseconds_t	get_time(void);
suseconds_t	get_time_diff(suseconds_t init_time);
int			ft_atoi_err(const char *str, char *err);

/*
 *	Functions used in memory allocation.
 */
t_pgrm_data	*clear_data(t_pgrm_data **data);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *s, int c, size_t n);

/*
 *	Functions used to display data.
 */
int			ft_putstr(int fd, char *str);
int			ft_putchar_err(int fd, char c, char *err);
int			ft_putnbr_long_err(int fd, unsigned long number, char *err);
int			ft_putnbr_err(int fd, int num, char *err);
int			ft_putstr_err(int fd, char *str, char *err);

/*
 *	Functions to display the states of the philosophers.
 */
int	display_fork(long ms, int philosopher, pthread_mutex_t *mutex);
int	display_eating(long ms, int philosopher, pthread_mutex_t *mutex);
int	display_sleeping(long ms, int philosopher, pthread_mutex_t *mutex);
int	display_thinking(long ms, int philosopher, pthread_mutex_t *mutex);
int	display_died(long ms, int philosopher, pthread_mutex_t *mutex);
int	display_state(long ms, int philo, char *state, pthread_mutex_t *mutex);


/*
 *	Actions of philsophers.
 */
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

/*
 *	Thread functions.
 */
char	init_philosophers(pthread_t *philos, t_pgrm_data *data);
void	wait_philosophers(pthread_t *philos, char n_philosophers);


//----------------------------------------------------------new functions


/*
 *	Functions to initialize the program correctly.
 */
char	init_data(int argc, char **argv, t_dinnertable *dinnertable,
	char *error_msg);
char	init_control(t_dinnertable *dinnertable, char **error_msg);



/*
 *	Printing an error when starting the program to stdout.
 */
void	print_error(const char *error_msg);


#endif
