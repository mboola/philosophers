/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:16:13 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:16:20 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_putnbr_err(int fd, int num, char *err)
{
	unsigned int	number;
	int				count;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar_err(fd, '-', err);
		number = num * -1;
	}
	else
		number = num;
	if (*err)
		return (count);
	return (count + ft_putnbr_long_err(fd, 0 + number, err));
}
