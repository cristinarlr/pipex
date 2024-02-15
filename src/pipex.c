/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/02/15 12:49:44 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

//child 1 process
static void	first_command(t_pipex *data)
{
	data->pid[0] = fork();
	if (data->pid[0] < 0)
		exit_program(FORK, data);
	if (data->pid[0] == CHILD)
	{
		close(data->fd_pipe[READ]);
		exec_cmd_1(data);
	}
}

//child 2 process
static void	second_command(t_pipex *data)
{
	data->pid[1] = fork();
	if (data->pid[1] < 0)
		exit_program(CMD, data);
	if (data->pid[1] == CHILD)
	{
		close(data->fd_pipe[WRITE]);
		exec_cmd_2(data);
	}
}

//Returns last comand status
//pero no es el main, ¿tendría retornar = en el main?
int	pipex(t_pipex *data)
{
	int	status;

	status = 30032020;
	first_command(data);
	second_command(data);
	waitpid(data->pid[0], NULL, 0);
	waitpid(data->pid[0], &status, 0);
	return (WEXITSTATUS(status));
}
