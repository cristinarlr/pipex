/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:02:40 by Cristina          #+#    #+#             */
/*   Updated: 2024/02/06 13:46:33 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/pipex.h"

void	exec_cmd_1(t_pipex *data)
{
	char	*path;
	
	//ft_printf("Dentro de exec_cmd_1\n");
	data->cmd_args_splitted = ft_split(data->argv[2], ' ');
	path = get_cmd_path_route(data, data->cmd_args_splitted[0]);
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
		exit(ft_printf("1 crear función exit_program, child1 dup2, close fds"));
	close(data->fd_infile);
	if (dup2(data->fd_pipe[WRITE], STDOUT_FILENO) == -1)
		exit(ft_printf("2 crear función exit_program, child1 dup2, close fds"));
	close(data->fd_pipe[WRITE]);
	if (execve(path, data->cmd_args_splitted, data->envp) == -1)
		exit(ft_printf("ERR execve crear función exit_program, exit child"));
}

void	exec_cmd_2(t_pipex *data)
{
	char	*path;
	
	//ft_printf("Dentro de exec_cmd_2\n");
	data->cmd_args_splitted = ft_split(data->argv[3], ' ');
	path = get_cmd_path_route(data, data->cmd_args_splitted[0]);
	if (dup2(data->fd_pipe[READ], STDIN_FILENO) == -1)
		exit(ft_printf("cmd2 1.crear función exit_program, child1 dup2, close fds"));
	close(data->fd_pipe[READ]);
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
		exit(ft_printf("cmd2 2.crear función exit_program, child1 dup2, close fds"));
	close(data->fd_outfile);
	if (execve(path, data->cmd_args_splitted, data->envp) == -1)
		exit(ft_printf("ERR cmd 2 execve crear función exit_program, exit child"));
}