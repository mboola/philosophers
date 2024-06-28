/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:16:13 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:16:20 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_MSG_H
# define DISPLAY_MSG_H

# ifndef FORK_TAKEN_MSG
#  define FORK_TAKEN_MSG "\033[0;34m has taken a fork\033[0m\n"
# endif

# ifndef EAT_MSG
#  define EAT_MSG "\033[0;35m is eating\033[0m\n"
# endif

# ifndef SLEEP_MSG
#  define SLEEP_MSG "\033[0;36m is sleeping\033[0m\n"
# endif

# ifndef THINKING_MSG
#  define THINKING_MSG "\033[0;37m is thinking\033[0m\n"
# endif

# ifndef DEATH_MSG
#  define DEATH_MSG "\033[0;33m died\033[0m\n"
# endif

#endif
