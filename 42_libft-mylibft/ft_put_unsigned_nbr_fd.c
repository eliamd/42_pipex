/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:46:36 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/01 15:49:06 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	char	numchar;
	int		count;

	count = 0;
	if (n >= 10)
	{
		count += ft_put_unsigned_nbr_fd(n / 10, fd) + \
		ft_put_unsigned_nbr_fd(n % 10, fd);
	}
	else
	{
		numchar = n + '0';
		write(fd, &numchar, 1);
		count++;
	}
	return (count);
}
