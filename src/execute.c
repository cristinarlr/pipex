/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:02:40 by Cristina          #+#    #+#             */
/*   Updated: 2024/03/12 13:11:17 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"


/* Verify infile and outfile fd */
void	check_and_open_fd(t_pipex *data, int file_stream)
{
	if (file_stream == INFILE)
	{
		if ((access(data->argv[1], F_OK) == -1)
			|| (access(data->argv[1], R_OK) == -1))
			exit_program(FILE_ERR, NULL);
		data->fd_infile = open(data->argv[1], O_RDONLY);
		if (data->fd_infile < 0)
			exit_program(FILE_ERR, data);
	}
	else if (file_stream == OUTFILE)
	{
		if ((access(data->argv[4], F_OK) == -1)
			|| (access(data->argv[4], W_OK) == -1))
			exit_program(FILE_ERR, NULL);
		data->fd_outfile = open(data->argv[4], O_CREAT
				| O_RDWR | O_TRUNC, 0644);
		if (data->fd_outfile < 0)
			exit_program(FILE_ERR, data);
	}
}

//TODO - Proteger !path, los dos dup y el execve. Pero poco a poco porque eso es lo que me ha estado dando errores.
//fd_pipe OPEN //to OPEN fd_infile
void	exec_cmd_1(t_pipex *data)
{
	char	*path;

	close(data->fd_pipe[READ]);
	//("---------inside exec_cmd_1\n");
	data->cmd_args_splitted = ft_split(data->argv[2], ' ');
	path = get_cmd_path_route(data, data->cmd_args_splitted[0]);
	if (!path)
		exit_program(NO_CMD, data);
	//ft_printf("path (cmd 1)= %s\n", path);
	check_and_open_fd(data, INFILE);
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
		exit_program(FILE_ERR, data);
	close(data->fd_infile);
	if (dup2(data->fd_pipe[WRITE], STDOUT_FILENO) == -1)
		exit_program(FILE_ERR, data);
	close(data->fd_pipe[WRITE]);
	if (execve(path, data->cmd_args_splitted, data->envp) == -1)
		exit_program(EXECVE, data);
}

//fd_pipe OPEN //to OPEN fd_outfile
void	exec_cmd_2(t_pipex *data)
{
	char	*path;

	close(data->fd_pipe[WRITE]);
	//ft_printf("--------inside exec_cmd_2\n");
	data->cmd_args_splitted = ft_split(data->argv[3], ' ');
	path = get_cmd_path_route(data, data->cmd_args_splitted[0]);
	if (!path)
		exit_program(NO_CMD, data);
	//ft_printf("path (cmd 2)= %s\n", path);
	check_and_open_fd(data, OUTFILE);
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
		exit_program(FILE_ERR, data);
	close(data->fd_outfile);
	if (dup2(data->fd_pipe[READ], STDIN_FILENO) == -1)
		exit_program(FILE_ERR, data);
	close(data->fd_pipe[READ]);
	if (execve(path, data->cmd_args_splitted, data->envp) == -1)
		exit_program(EXECVE, data);
		//exit(127);
}

/* ---------------------------------------------- */

/* child process 1 */
/* void	exec_cmd_1(t_pipex *data)
{
	char	*path;

	close(data->fd_pipe[READ]);
	check_and_open_fd(data, INFILE);
	data->cmd_args_splitted = ft_split(data->argv[2], ' ');
	path = get_cmd_path_route(data, data->cmd_args_splitted[0]);
	ft_printf("path 1= %s\n", path);
	if (!path)
	{
		ft_printf("INVALID PATH EN CMD 1\n");
		exit_program(NO_CMD, data);
	}
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
		exit_program(FILE_ERR, data);
	close(data->fd_infile);
	if (dup2(data->fd_pipe[WRITE], STDOUT_FILENO) == -1)
		exit_program(FILE_ERR, data);
	close(data->fd_pipe[WRITE]);
	if (execve(path, data->cmd_args_splitted, data->envp) == -1)
		exit_program(EXECVE, data);
} */

/* child process 2 */
/* void	exec_cmd_2(t_pipex *data)
{
	char	*path;

	ft_printf("---------exec_cmd_2: child process 2\n");
	close(data->fd_pipe[WRITE]);
	check_and_open_fd(data, OUTFILE);
	data->cmd_args_splitted = ft_split(data->argv[3], ' ');
	path = get_cmd_path_route(data, data->cmd_args_splitted[0]);
	ft_printf("path 2= %s\n", path);
	if (!path)
	{
		ft_printf("INVALID PATH EN CMD 2\n");
		exit_program(NO_CMD, data);
	}
	ft_printf("a- \n");
	if (dup2(data->fd_pipe[READ], STDIN_FILENO) == -1)
		exit_program(FILE_ERR, data);
	ft_printf("b- \n");
	ft_printf("data->fd_outfile = %i\n", data->fd_outfile);
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
	{
		ft_printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		exit_program(FILE_ERR, data);
	}
	dup2(STDOUT_FILENO, data->fd_outfile);
	ft_printf("c- \n");
	close(data->fd_pipe[READ]);
	close(data->fd_outfile);
	ft_printf("d- \npath = %s\n", path);
	printf("execve_var = %i", execve(path, data->cmd_args_splitted, data->envp));
	if (execve(path, data->cmd_args_splitted, data->envp) != -1)
	{
		ft_printf("---------PROBLEM EXECVE child process 2 bef execve\n");
		exit_program(EXECVE, data);
	}
	ft_printf("---------EXIT child process 2 bef execve\n");
} */
