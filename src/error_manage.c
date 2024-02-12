/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:43:34 by crramire          #+#    #+#             */
/*   Updated: 2024/02/12 13:01:02 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array)
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

void	exit_program(t_error code, int fd, t_pipex *data)
{
	if (code == ENV)
		perror("Environment error");
	else if (code == FILE)
		perror("File problem");
	else if (code == NO_CMD)
		perror("Command not found");
	else if (code == CMD)
		perror("Command not found");
	else if (code == MALLOC)
		perror("Malloc error");
	close_fds(data);
	if (cmd)
		free(cmd);
	if (data->envp_path_splitted)
		free_array(data->envp_path_splitted);
	if (data->cmd_args_splitted)
		free_array(data->cmd_args_splitted);
	if (CMD)
		exit(127);
	exit(1);
}
