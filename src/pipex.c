/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:54:18 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/19 18:14:35 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_args(int argc, char **argv)
{
	int 	index;
	char 	*cmd_dir;

	index = 2;
	if (argc < 5 || !argv[1] || access(argv[1], F_OK) == -1)
		return (0);

	while (argv[index] && index < argc - 1)
	{
		cmd_dir = ft_strjoin("/usr/bin/", argv[index]);
		if(!cmd_dir)
			return (0);
		if (access(cmd_dir, F_OK) == -1)
		{
			free(cmd_dir);
			return(0);
		}
		else
			index++;
		free(cmd_dir);
	}
	return (1);
}

int main(int argc, char **argv)
{
	char *infile;
	char *cmd1;
	char *cmd2;
	char *outfile;
	ft_printf("res -> %i", check_args(argc, argv));


	return 0;
}
