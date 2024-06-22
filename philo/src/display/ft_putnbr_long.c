/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:16:13 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:16:20 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_putnbr_long(int fd, unsigned long number)
{
	int	count;

	if (number / 10 < 1)
		return (ft_putchar(fd, DEC_BASE[number]));
	else
	{
		count = ft_putnbr_long(fd, number / 10);
		count += ft_putchar(fd, DEC_BASE[number % 10]);
		return (count);
	}
}
