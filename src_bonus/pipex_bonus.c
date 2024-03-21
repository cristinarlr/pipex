/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/03/21 15:23:25 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

//PARENT - managing FIRST CHILD //fd_pipe OPEN
static void	first_command(t_pipex *data)
{
	if (pipe(data->fd_pipe) < 0)
		exit(EXIT_FAILURE);
	data->pid[0] = fork();
	if (data->pid[0] < 0)
		exit_program(FORK, data);
	//printf("CHILD 1 - pid[0]: %i\n", data->pid[0]);
	if (data->pid[0] == CHILD)
		exec_first_cmd(data);
	data->fd_current_pipe = data->fd_pipe[READ];
}

//PARENT - managing MIDDLE CHILDS//fd_pipe OPEN
static void	middle_command(t_pipex *data)
{
	//FIXME - Me está dando un error de lectura de file, ver todas las salidas de error
	ft_printf("MIDDLE_COMMAND\n");
	if (data->pid[0] < 0)
		exit_program(FORK, data);
	data->pid[0] = fork();
	if (data->pid[0] == CHILD)
		exec_middle_cmd(data);
	//Guardar el fd_read en upstream para el siguiente comando
	data->fd_current_pipe = data->fd_pipe[READ];
}

//PARENT - managing LAST CHILD //fd_pipe OPEN
static void	last_command(t_pipex	*data)
{
	//ft_printf("-------------------inside second_command\n");
	data->pid[1] = fork();
	if (data->pid[1] < 0)
		exit_program(FORK, data);
	//ft_printf("CHILD 2 - pid[1]: %i\n", data->pid[1]);
	if (data->pid[1] == CHILD)
	{
		ft_printf("data->fd_pipe")
		exec_last_cmd(data);
	}
}

//Returns last comand status to main
int	pipex(t_pipex	*data)
{
	int	status[2];

	//ft_printf("-------------------inside pipex\n");
	status[0] = 3003;
	status[1] = 0403;
	data->middle_cmds = data->argc - 5;
	/* El primer pipe lo hago dentro de first_cmd en padre */
	first_command(data);
	while (data->middle_cmds > 0)
	{
		if (pipe(data->fd_pipe) < 0)
			exit(EXIT_FAILURE);
		middle_command(data);
		data->middle_cmds--;
	}
	last_command(data);
	close (data->fd_pipe[0]);
	close (data->fd_pipe[1]);
	waitpid(data->pid[0], &status[0], 0);
	waitpid(data->pid[1], &status[1], 0);
	// executing_check(&status[0], 1);
	// executing_check(&status[1], 2);
	exit(WEXITSTATUS(status[1]));
}
