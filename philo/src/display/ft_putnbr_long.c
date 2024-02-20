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

int	ft_putnbr_long_err(int fd, unsigned long number, char *err)
{
	int	count;

	if (number / 10 < 1)
		return (ft_putchar_err(fd, DEC_BASE[number], err));
	else
	{
		count = ft_putnbr_long_err(fd, number / 10, err);
		if (!*err)
			count += ft_putchar_err(fd, DEC_BASE[number % 10], err);
		return (count);
	}
}
