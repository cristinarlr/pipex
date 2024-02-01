/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:59 by crramire          #+#    #+#             */
/*   Updated: 2024/01/31 11:01:56 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/pipex.h"

int	pipex(t_pipex *data)
{
	(void) data;
	return (NO_ERROR);
	//pipe(data->fd_pipe);

}

int	init_data_structure(t_pipex *data)
{
	data->fd_infile = open(data->argv[1], O_RDONLY);
	data->fd_outfile = open(data->argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_infile < 0 || data->fd_outfile < 0)
	{
		// ft de close 2 files and exit
		return (ERROR);
	}
	if (pipe(data->fd_pipe) != 0)
	{
		// ft de close 4 files and exit
		return (ERROR);
	}
	data->envp_path = NULL;
	data->cmd_args_splitted = NULL;
	return (NO_ERROR);

}

static void	check_program_args(int argc, char **argv, char **envp)
{
	if (!envp)
		exit(ft_printf("crear función exit_program"));
	//exit(write(1, "Error: envp", 11));
	if (argc != 5)
		exit(ft_printf("crear función exit_program"));
	//return (write(1, USAGE, 40));
	if ((access(argv[1], F_OK) == -1))
		exit(ft_printf("crear función exit_program"));
	if ((access(argv[1], R_OK) == -1))
		exit(ft_printf("crear función exit_program"));
	if ((access(argv[4], F_OK) == -1))
		exit(ft_printf("crear función exit_program"));
	if ((access(argv[4], W_OK) == -1))
		exit(ft_printf("crear función exit_program"));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	check_program_args(argc, argv, envp);
	ft_printf("%s PID: %i\n", argv[0], getpid());
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	data.cmds[0] = *(argv + 2);
	data.cmds[1] = *(argv + 3);
	init_data_structure(&data);
	//find_path_in_envp(&data);
	pipex(&data);
	return (0);
}
