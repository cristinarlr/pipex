/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:59 by crramire          #+#    #+#             */
/*   Updated: 2024/03/21 15:18:31 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

int	init_data_structure(t_pipex *data)
{
	data->middle_cmds = 0;
	data->fd_current_pipe = 0;
	data->fd_infile = 0;
	data->fd_outfile = 0;
	data->fd_pipe[0] = -1;
	data->fd_pipe[1] = -1;
	data->envp_path_splitted = NULL;
	data->cmd_args_splitted = NULL;
	data->pid[0] = -1;
	data->pid[1] = -1;
	return (NO_ERROR);
}

/* void	check_leaks(void)
{
	system("leaks -q pipex");
} */

static void	check_program_args(int argc, char **envp)
{
	if (!envp)
		exit_program(ENV, NULL);
	if (argc < 5)
	{
		perror("Usage: ./pipex infile \"cmd1\" \"cmd2\" \"cmd3\" outfile\n");
		exit(0);
	}
}

/* Initialize data structure, checking environment, call to pipex */
int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	//atexit(check_leaks);
	ft_printf("%s PID: %i\n", argv[0], getpid());
	check_program_args(argc, envp);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
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
