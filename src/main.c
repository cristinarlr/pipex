/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:59 by crramire          #+#    #+#             */
/*   Updated: 2024/02/13 11:03:42 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	init_data_structure(t_pipex *data)
{
	//ft_printf("Dentro de init_data_structure\n");
	data->fd_infile = open(data->argv[1], O_RDONLY);
	data->fd_outfile = open(data->argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_infile < 0)
		exit_program(FILE, data->fd_infile, NULL);
	if (data->fd_outfile < 0)
		exit_program(FILE, data->fd_outfile, NULL);
	if (pipe(data->fd_pipe) == -1)
	{
		ft_printf("problem doing PIPE");
		// ft de close 4 files and exit, no processes opened
		return (ERROR);
	}
	data->envp_path_splitted = NULL;
	data->cmd_args_splitted = NULL;
	data->pid[0] = -1;
	data->pid[1] = -1;
	//data->fd_pipe[READ] = -1;
	//data->fd_pipe[WRITE] = -1;
	return (NO_ERROR);

}

static void	check_program_args(int argc, char **argv, char **envp)
{
	//ft_printf("Dentro de check_program_args\n");
	if (!envp)
		exit_program(ENV, NULL, NULL);
	if (argc != 5)
		perror("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n");
	if ((access(argv[1], F_OK) == -1) || (access(argv[1], R_OK) == -1))
		exit_program(FILE, NULL, NULL);
	if ((access(argv[4], F_OK) == -1) || (access(argv[4], W_OK) == -1))
		exit_program(FILE, NULL, NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	ft_printf("%s PID: %i\n", argv[0], getpid());
	/* Me ha dicho Luis que esto es mejor hacer check program args dentro de child */
	check_program_args(argc, argv, envp);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	data.cmds[0] = *(argv + 2);
	data.cmds[1] = *(argv + 3);
	if (init_data_structure(&data) == ERROR)
		perror("Error: Problem initializing structure");
	if (find_path_in_envp(&data) == 0)
	{
		perror("Error: No PATH finded");
		exit(errno);
	}
	pipex(&data);
	return (0);
}
