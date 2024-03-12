/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:02:40 by Cristina          #+#    #+#             */
/*   Updated: 2024/03/12 07:06:42 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	print_array(char **arr)
{
	int	i;
	
	i = 0;
	while (arr[i] != NULL)
	{
		printf("arr[%i] = %s\n", i, arr[i]);
		i++;
	}
	printf("arr[%i] = %s\n", i, arr[i]);
}

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
	printf("\n---------inside exec_cmd_1\n");
	printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, data->argv[2] = %s\n", data->argv[2]);
	data->cmd_args_splitted = ft_split(data->argv[2], ' ');
	printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, \n");
	print_array(data->cmd_args_splitted);
	path = get_cmd_path_route(data, data->cmd_args_splitted[0]);
	printf("path (cmd 1)= %s\n", path);
	printf("Array Comando 1:\n");
	print_array(data->cmd_args_splitted);
	check_and_open_fd(data, INFILE);
	dup2(data->fd_infile, STDIN_FILENO);
	close(data->fd_infile);
	dup2(data->fd_pipe[WRITE], STDOUT_FILENO);
	close(data->fd_pipe[WRITE]);
	if (execve("/bin/ls", data->cmd_args_splitted, data->envp) == -1)
		exit(EXIT_FAILURE);
	// if (execve(path, data->cmd_args_splitted, data->envp) == -1)
	// 	exit(EXIT_FAILURE);
}

//fd_pipe OPEN //to OPEN fd_outfile
void	exec_cmd_2(t_pipex *data)
{
	//char	*path;

	close(data->fd_pipe[WRITE]);
	printf("\n--------inside exec_cmd_2\n");
	close(data->fd_pipe[WRITE]);
	data->cmd_args_splitted = ft_split(data->argv[3], ' ');
	//path = get_cmd_path_route(data, data->cmd_args_splitted[0]);
	//ft_printf("path (cmd 2)= %s\n", path);
	printf("Array Comando 2:\n");
	print_array(data->cmd_args_splitted);
	check_and_open_fd(data, OUTFILE);
	//el outfile se convierte en stdout
	dup2(data->fd_outfile, STDOUT_FILENO);
	close(data->fd_outfile);
	dup2(data->fd_pipe[READ], STDIN_FILENO);
	close(data->fd_pipe[READ]);
	//a partir de aquí todo se imprime en outfile
	//FIXME - When I want to execute < ./pipex infile "ls" "wc" outfile > the program gets stuck. It seems like an argument in execve is not working well. But is weird because this command here works well < ./pipex infile "ls" "ls" outfile >, it seems that it only happens with "wc". Check the 3 args in execve
	if (execve("/usr/bin/sort", data->cmd_args_splitted, data->envp) < 0)
		exit(127);
	// if (execve(path, data->cmd_args_splitted, data->envp) < 0)
	// 	exit(127);
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