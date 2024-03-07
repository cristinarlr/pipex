/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/03/07 13:55:12 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

//child 1 process pid0
static void	first_command(t_pipex *data)
{
	data->pid[0] = fork();
	if (data->pid[0] < 0)
		exit_program(FORK, data);
	printf("CHILD 1 - pid[0]: %i\n", data->pid[0]);
	if (data->pid[0] == CHILD)
		exec_cmd_1(data);
}

//child 2 process pid1
static void	second_command(t_pipex *data)
{
	data->pid[1] = fork();
	if (data->pid[1] < 0)
		exit_program(CMD, data);
	printf("CHILD 2 - pid[1]: %i\n", data->pid[1]);
	if (data->pid[1] == CHILD)
		exec_cmd_2(data);
}

//Returns last comand status
//pero no es el main, ¿tendría retornar = en el main?
int	pipex(t_pipex *data)
{
	//int	status[2];
	int	status;

	printf("-------------------inside pipex\n");

	first_command(data);
	second_command(data);
	//REVIEW - estos waitpid estan correctos, el de pid[1] hay que hacer algo?
	waitpid(data->pid[0], NULL, 0);
	waitpid(data->pid[1], &status, 0);
	close_fds(data);
	return (WEXITSTATUS(status));
}
