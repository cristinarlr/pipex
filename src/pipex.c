/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/03/12 12:36:34 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

//child 1 process pid0 //fd_pipe OPEN
static void	first_command(t_pipex *data)
{
	//printf("-------------------inside first_command\n");
	data->pid[0] = fork();
	if (data->pid[0] < 0)
	{
		ft_printf("Ha habido un problema con FORK en first_command\n");
		exit_program(FORK, data);
	}
	//printf("CHILD 1 - pid[0]: %i\n", data->pid[0]);
	if (data->pid[0] == CHILD)
		exec_cmd_1(data);
}

//child 2 process pid1 //fd_pipe OPEN
static void	second_command(t_pipex *data)
{
	//ft_printf("-------------------inside second_command\n");
	data->pid[1] = fork();
	if (data->pid[1] < 0)
	{
		ft_printf("Ha habido un problema con FORK en second_command\n");
		exit_program(FORK, data);
	}
	//ft_printf("CHILD 2 - pid[1]: %i\n", data->pid[1]);
	if (data->pid[1] == CHILD)
		exec_cmd_2(data);
}

//Returns last comand status to main
int	pipex(t_pipex *data)
{
	int	status[2];

	//ft_printf("-------------------inside pipex\n");
	status[0] = 3003;
	status[1] = 0403;
	if (pipe(data->fd_pipe) < 0)
		exit(EXIT_FAILURE);
	first_command(data);
	second_command(data);
	close (data->fd_pipe[0]);
	close (data->fd_pipe[1]);
	waitpid(data->pid[0], &status[0], 0);
	waitpid(data->pid[1], &status[1], 0);
	// executing_check(&status[0], 1);
	// executing_check(&status[1], 2);
	exit(WEXITSTATUS(status[1]));
}
