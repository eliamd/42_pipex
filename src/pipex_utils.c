/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:20:05 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/29 16:45:06 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freetab(char **tab)
{
	if (!tab)
		return ;
	while (*tab)
	{
		free(*tab);
		++tab;
	}
}

t_args_execute	ft_create_args(char **argv, int *fd, int fd_in, int fd_out)
{
	t_args_execute	args;

	args.argv = argv;
	args.fd = fd;
	args.fdin = fd_in;
	args.fdout = fd_out;
	return (args);
}

void	ft_redirect_fd(t_args_execute args, int mode)
{
	if (mode == 1)
	{
		dup2(args.fdin, STDIN_FILENO);
		dup2(args.fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(args.fd[0], STDIN_FILENO);
		dup2(args.fdout, STDOUT_FILENO);
	}
	close(args.fd[0]);
	close(args.fd[1]);
}
