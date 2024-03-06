/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:59 by crramire          #+#    #+#             */
/*   Updated: 2024/03/06 13:42:18 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	init_data_structure(t_pipex *data)
{
	data->fd_infile = 0;
	data->fd_outfile = 0;
	if (pipe(data->fd_pipe) == -1)
		exit_program(FILE_ERR, data);
	data->envp_path_splitted = NULL;
	data->cmd_args_splitted = NULL;
	data->pid[0] = -1;
	data->pid[1] = -1;
	return (NO_ERROR);
}

void	check_leaks(void)
{
	system("leaks -q pipex");
}

static void	check_program_args(int argc, char **argv, char **envp)
{
	(void) argv;

	atexit(check_leaks);
	if (!envp)
		exit_program(ENV, NULL);
	if (argc != 5)
		perror("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n");
}

/* Initialize data structure, checking environment, call to pipex */
int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	ft_printf("%s PID: %i\n", argv[0], getpid());
	//TODO - lpastor mejor hacer check program args dentro de child por qué, era por los open fd
	check_program_args(argc, argv, envp);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	data.cmds[0] = *(argv + 2);
	data.cmds[1] = *(argv + 3);
	if (init_data_structure(&data) == ERROR)
	{
		perror("Problem initializing structure");
		exit(errno);
	}
	if (find_path_in_envp(&data) == 0)
	{
		perror("No PATH finded");
		exit(errno);
	}
	return (pipex(&data));
}

//FIXME - You have access to multiple processes named pipex:
//    a) 32372 ./pipex
//    b) 32577 ./pipex
//    c) 32655 ./pipex
//Which process? (letter or PID)
