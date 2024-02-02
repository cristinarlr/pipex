/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/02/02 15:45:42 by crramire         ###   ########.fr       */
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
	printf("data->pid[0] = %i\n", data->pid[0]);
}

int	pipex(t_pipex *data)
{
	(void) data;

	ft_printf("Dentro de pipex\n");
	first_command(data);
	return (NO_ERROR);
}
