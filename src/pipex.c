/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/02/13 10:48:50 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

//child 1 process
static void	first_command(t_pipex *data)
{
	ft_printf("Dentro de first_command\n");
	data->pid[0] = fork();
	ft_print_pids(data->pid[0]);
	if (data->pid[0] < 0)
		exit(ft_printf("crear función exit_program, exit parent)"));
	if (data->pid[0] == CHILD)
	{
		close(data->fd_pipe[READ]);
		exec_cmd_1(data);
	}
}

//child 2 process
static void	second_command(t_pipex *data)
{
	ft_printf("Dentro de second_command\n");
	data->pid[1] = fork();
	ft_print_pids(data->pid[1]);
	if (data->pid[1] < 0)
		exit(ft_printf("sec_cmd crear función exit_program, exit parent)"));
	if (data->pid[1] == CHILD)
	{
		close(data->fd_pipe[WRITE]);
		exec_cmd_2(data);
	}
}

int	pipex(t_pipex *data)
{
	int	status;

 	//ft_printf("Dentro de pipex\n");
	status = 30032020;
	first_command(data);
	second_command(data);
	waitpid(data->pid[0], NULL, 0);
	waitpid(data->pid[0], &status, 0);
	return (WEXITSTATUS(status));
}
