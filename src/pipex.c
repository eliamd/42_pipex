/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:54:18 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/28 12:24:06 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_chlid_process(t_args_execute args, int index, int mode)
{
	char		**arg_tab;
	char		*cmd_path;

	arg_tab = ft_split(args.argv[index], ' ');
	if (!arg_tab)
		exit(EXIT_FAILURE);
	cmd_path = ft_get_cmd_path(arg_tab[0]);
	if (!cmd_path)
	{
		ft_freetab(arg_tab);
		exit(EXIT_FAILURE);
	}
	ft_redirect_fd(args, mode);
	execv(cmd_path, arg_tab);
	perror("Erreur : execv");
	return (ft_freetab(arg_tab), free(arg_tab), free(cmd_path), \
	exit(EXIT_FAILURE));
}

int	ft_execute(t_args_execute args, int index, int mode)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (perror("Erreur : fork."), 0);
	if (pid == 0)
	{
		ft_chlid_process(args, index, mode);
	}
	return (pid);
}

int	ft_setup_files(char **argv, int *fd_in, int *fd_out)
{
	*fd_in = open(argv[1], O_RDONLY);
	if (*fd_in == -1)
		return (perror("Erreur fd_in dans ft_setup_files"), 0);
	*fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd_out == -1)
	{
		close(*fd_in);
		return (perror("Erreur fd_in dans ft_setup_files"), 0);
	}
	return (1);
}

void	ft_pipex(char **argv, int *fd, int fd_in, int fd_out)
{
	int				pid1;
	int				pid2;

	pid1 = 0;
	pid2 = 0;
	pid1 = ft_execute(ft_create_args(argv, fd, fd_in, fd_out), 2, 1);
	pid2 = ft_execute(ft_create_args(argv, fd, fd_in, fd_out), 3, 2);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	close(fd_in);
	close(fd_out);
}

int	main(int argc, char **argv)
{
	int				fd[2];
	int				fd_in_file;
	int				fd_out_file;

	if (check_args(argc, argv) == 0)
		return (perror("Erreur : check_args."), exit(EXIT_FAILURE), 1);
	if (ft_setup_files(argv, &fd_in_file, &fd_out_file) == 0)
		return (perror("Erreur : ft_setup_files."), exit(EXIT_FAILURE), 1);
	if (pipe(fd) == -1)
		return (perror("Erreur : pipe."), exit(EXIT_FAILURE), 1);
	ft_pipex(argv, fd, fd_in_file, fd_out_file);
}
