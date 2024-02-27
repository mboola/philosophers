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

int	ft_putstr_err(int fd, char *str, char *err)
{
	int	count;

	if (str == NULL)
		return (ft_putstr_err(fd, "(null)", err));
	count = 0;
	while (!*err && *str != '\0')
	{
		ft_putchar_err(fd, *str, err);
		str++;
		count++;
	}
	return (count);
}

int	ft_putstr(int fd, char *str)
{
	int		count;
	char	err;

	if (str == NULL)
		return (ft_putstr(fd, "(null)"));
	err = 0;
	count = 0;
	while (!err && *str != '\0')
	{
		ft_putchar_err(fd, *str, &err);
		str++;
		count++;
	}
	if (err)
		return (-1);
	return (count);
}
