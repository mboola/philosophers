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

int	ft_putnbr(int fd, int num)
{
	unsigned int	number;
	int				count;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar(fd, '-');
		number = num * -1;
	}
	else
		number = num;
	return (count + ft_putnbr_long(fd, 0 + number));
}
