/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:54:18 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/25 18:11:15 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_execute(int index, char **argv, int *fd, int pid, int mode)
{
	char **arg_tab;
	char *cmd_dir;

	arg_tab = ft_split(argv[index], ' ');
	cmd_dir = ft_strjoin("/usr/bin/", arg_tab[0]);
		printf("cmd_dir : %s\n", cmd_dir);
	pid = fork();
	if (pid < 0)
		return (perror("Erreur : fork."), 0);
	if (pid == 0)
	{
		if (mode == 1)
			dup2(fd[1], STDOUT_FILENO);
		else
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execv(cmd_dir, arg_tab);
		perror("Erreur : execv");
        free(arg_tab);
        free(cmd_dir);
        exit(EXIT_FAILURE);
	}
	return (pid);
}

int main(int argc, char **argv)
{
	int fd[2];
	int pid1;
	int pid2;

	if (check_args(argc, argv) == 0)
		return (perror("Erreur : Arguments non conformes."), 1);
	if (pipe(fd) == -1)
		return (perror("Erreur : Pipe."), 1);
	pid1 = 0;
	pid2 = 0;

	pid1 = ft_execute(2, argv, fd, pid1, 1);
	pid2 = ft_execute(3, argv, fd, pid2, 2);

	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return 0;
}
