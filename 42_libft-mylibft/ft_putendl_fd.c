/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:34:23 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:15:44 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ft_putendl_fd writes the string 's' followed by an '\n' to 'fd'.
Takes 's' (string to write) and 'fd' (file descriptor).
Uses write() to write the string and the '\n'.
*/

void	ft_putendl_fd(char *s, int fd)
{
	int	str_len;

	str_len = ft_strlen(s);
	write(fd, s, str_len);
	write(fd, "\n", 1);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	printf("===== RESULT Putstr fd =====\n");
// 	ft_putendl_fd("123", 1);
// 	printf("=============================\n");
// 	return (1);
// }
