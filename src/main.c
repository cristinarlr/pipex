/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:59 by crramire          #+#    #+#             */
/*   Updated: 2024/01/30 13:42:55 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/pipex.h"

/* int	pipex(t_pipex *data)
{
	pipe(data->fd_pipe);

} */

int	init_data_structure(t_pipex *data)
{
	data->fd_infile = open(data->argv[1], O_RDONLY);
	data->fd_outfile = open(data->argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_infile < 0 || data->fd_outfile < 0)
	{
		// ft de close 2 files and exit
		return (ERROR);
	}
	if (pipe(data->fd_pipe) != 0)
	{
		// ft de close 4 files and exit
		return (ERROR);
	}
	data->env_path = NULL;
	data->cmd_args_splitted = NULL;

}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc != 5)
		return (write(1, USAGE, 40));
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->cmds[0] = *(argv + 2);
	data->cmds[1] = *(argv + 3);
	init_data_structure(data);
	pipex(data);
	return (0);
}
