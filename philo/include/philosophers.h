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

# ifndef DEC_BASE
#  define DEC_BASE "0123456789"
# endif

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

/*
 *	Struct used store the program information.
 */
typedef struct s_program_data {
	int		n_philosophers;
	int		n_forks;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		n_times_to_eat;
	char	count_eating;
	char	ended;
}	t_program_data;

/*
 *	Functions used when converting input to data the program will use.
 */
t_program_data	convert_input(int argc, char **argv, char *err);
int				ft_atoi_err(const char *str, char *err);

/*
 *	Functions used in memory allocation.
 */
void			*ft_calloc(size_t count, size_t size);

/*
 *	Functions used to display data.
 */
int				ft_putchar_err(int fd, char c, char *err);
int				ft_putnbr_long_err(int fd, unsigned long number, char *err);
int				ft_putnbr_err(int fd, int num, char *err);
int				ft_putstr_err(int fd, char *str, char *err);

/*
 *	Functions to display the states of the philosophers.
 */
int				display_fork(long ms, int philosopher);
int				display_eating(long ms, int philosopher);
int				display_sleeping(long ms, int philosopher);
int				display_thinking(long ms, int philosopher);
int				display_died(long ms, int philosopher);
int				display_state(long ms, int philosopher, char *state);

#endif
