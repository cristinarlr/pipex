/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:43:34 by crramire          #+#    #+#             */
/*   Updated: 2024/02/15 12:47:17 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void close_fds(t_pipex *data)
{
	if (data->fd_infile > 0)
		close(data->fd_infile);
	if (data->fd_outfile > 0)
		close(data->fd_outfile);
	if (*(data->fd_pipe) > 0)
		close(*(data->fd_pipe));
	if (*(data->fd_pipe + 1) > 0)
		close(*(data->fd_pipe));
}

void	exit_program(t_error code, t_pipex *data)
{
	ft_printf("Dentro de exit_program\n");
	if (code == ENV)
		perror("Environment error");
	else if (code == FILE_ERR)
		perror("File problem");
	else if (code == NO_CMD)
		perror("Command not found");
	else if (code == CMD)
		perror("Problem with command");
	else if (code == MALLOC)
		perror("Malloc error");
	else if (code == FORK)
		perror("Problem in process forking");
	else if (code == EXECVE)
		perror("Problem in process executing");
	if (data == NULL)
		exit(-1);
	close_fds(data);
	if (data->envp_path_splitted)
		free_array(data->envp_path_splitted);
	if (data->cmd_args_splitted)
		free_array(data->cmd_args_splitted);
	if (CMD)
		exit(127);
	exit(1);
}
