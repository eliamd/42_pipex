/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:34:23 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/04 13:53:53 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ft_putstr_fd writes string 's' to file 'fd'.
Takes 's' (string to write) and 'fd' (file descriptor).
Uses write() to write the string to the file.
*/

int	ft_putstr_fd(char *s, int fd)
{
	int	str_len;

	if (s)
	{
		str_len = ft_strlen(s);
		return (write(fd, s, str_len));
	}
	write(fd, "(null)", 6);
	return (6);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	printf("===== RESULT Putstr fd =====\n");
// 	ft_putstr_fd("123", 1);
// 	printf("=============================\n");
// 	return (1);
// }
