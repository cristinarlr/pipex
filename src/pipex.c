/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/02/06 12:37:32 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
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
		ft_printf("Dentro de CHILD 1\n");
		close(data->fd_pipe[READ]);
		exec_cmd_1(data);
	}
	else
		wait(NULL);
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
	(void) data;

	ft_printf("Dentro de pipex\n");
	first_command(data);
	second_command(data);
	return (NO_ERROR);
}
