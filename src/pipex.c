/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/02/05 14:56:17 by Cristina         ###   ########.fr       */
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
		//meter todo lo que viene despues en exec_input_cmd(data)?;
		if (dup2(data->fd_infile, STDIN_FILENO) < 0)
			exit(ft_printf("1 crear función exit_program, child1 dup2, close fds"));
		close(data->fd_infile);
		//if (dup2(data->fd_pipe[WRITE], STDOUT_FILENO) < 0)
		//	exit(ft_printf("2 crear función exit_program, child1 dup2, close fds"));
		//close(data->fd_pipe[WRITE]);
		if (execve(get_cmd_path_route(data, data->argv[2]), data->cmd_args_splitted, data->envp) == -1)
			exit(ft_printf("ERR execve crear función exit_program, exit child"));
		ft_printf("SUCCESS CHILD 1\n");
	}
	else
		wait(NULL);
}

/* //child 2 process
static void second_command(t_pipex *data)
{

	
	
} */

int	pipex(t_pipex *data)
{
	(void) data;

	ft_printf("Dentro de pipex\n");
	first_command(data);
	return (NO_ERROR);
}
