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

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# ifndef BAD_PARAMS
#  define BAD_PARAMS "ERROR: n param must be between 5 and 6.\n"
# endif

# ifndef MAX_THREADS_ERROR
#  define MAX_THREADS_ERROR "ERROR: max threads surpassed.\n"
# endif

# ifndef MAX_INT_OVERFLOW
#  define MAX_INT_OVERFLOW "ERROR: number inputed superior to int.\n"
# endif

# ifndef VALUE_INFERIOR_MIN
#  define VALUE_INFERIOR_MIN "ERROR: num inputed cannot be that low.\n"
# endif

#endif
