/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:59 by crramire          #+#    #+#             */
/*   Updated: 2024/02/15 16:08:51 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	init_data_structure(t_pipex *data)
{
	//data->fd_infile = open(data->argv[1], O_RDONLY);
	//data->fd_outfile = open(data->argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	/* if (data->fd_infile < 0)
		exit_program(FILE_ERR, data); */
	/* if (data->fd_outfile < 0)
		exit_program(FILE_ERR, data); */
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

static void	check_program_args(int argc, char **argv, char **envp)
{
	(void) argv;

	if (!envp)
		exit_program(ENV, NULL);
	if (argc != 5)
		perror("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n");
	/* if ((access(argv[1], F_OK) == -1) || (access(argv[1], R_OK) == -1))
		exit_program(FILE_ERR, NULL);
	if ((access(argv[4], F_OK) == -1) || (access(argv[4], W_OK) == -1))
		exit_program(FILE_ERR, NULL); */
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
	{
		perror("Problem initializing structure");
		exit(errno);
	}
	if (find_path_in_envp(&data) == 0)
	{
		perror("No PATH finded");
		exit(errno);
	}
	pipex(&data);
	return (0);
}
