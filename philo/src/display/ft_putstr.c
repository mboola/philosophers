/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:14:24 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:14:49 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_putstr(int fd, const char *str)
{
	int		count;

	if (str == NULL)
		return (ft_putstr(fd, "(null)"));
	count = 0;
	while (*str != '\0')
	{
		ft_putchar(fd, *str);
		str++;
		count++;
	}
	return (count);
}
