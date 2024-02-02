/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/02/02 13:20:16 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/pipex.h"

//child 1 process
//fd[0] is to write
//fd[0] is to read
static void	first_command(t_pipex *data)
{
	data->pid[0] = fork();
	if (data->pid[0] < 0)
		exit(ft_printf("crear función exit_program - invalid PATH input"));
	if (data->pid[0] == 0)
	{
		close(data->fd[0]);
		execute_command();
	}
}

int	pipex(t_pipex *data)
{
	first_command(data)
	return (NO_ERROR);
}
