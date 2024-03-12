/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:48:47 by crramire          #+#    #+#             */
/*   Updated: 2024/03/12 07:08:26 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

//child 1 process pid0 //fd_pipe OPEN
static void	first_command(t_pipex *data)
{
	printf("\n-------------------inside first_command\n");
	data->pid[0] = fork();
	if (data->pid[0] < 0)
	{
		ft_printf("Ha habido un problema con FORK en first_command\n");
		exit_program(FORK, data);
	}
	printf("CHILD 1 - pid[0]: %i\n", data->pid[0]);
	if (data->pid[0] == CHILD)
		exec_cmd_1(data);
}

//child 2 process pid1 //fd_pipe OPEN
static void	second_command(t_pipex *data)
{
	printf("\n-------------------inside second_command\n");
	data->pid[1] = fork();
	if (data->pid[1] < 0)
	{
		ft_printf("Ha habido un problema con FORK en second_command\n");
		exit_program(FORK, data);
	}
	printf("CHILD 2 - pid[1]: %i\n", data->pid[1]);
	if (data->pid[1] == CHILD)
		exec_cmd_2(data);
}

void	executing_check(int *status, int command)
{
	int	status_code;
	
	status_code = 0;
	if (WIFEXITED(*status))
	{
		printf("..............inside executing_check Command %i\n", command);
		status_code = WEXITSTATUS(status[0]);
		if (status_code == 0)
			printf("..............SUCCES Command %i\n", command);
		else
			printf(".............. 🔥 FAILURE Command %i with statusCode %d\n", command, status_code);
	}
}

//Returns last comand status
//pero no es el main, ¿tendría retornar = en el main?
int	pipex(t_pipex *data)
{
	int	status[2];
	
	printf("-------------------inside pipex\n");
	status[0] = 3003;
	status[1] = 0403;
	if (pipe(data->fd_pipe) < 0)
		exit(EXIT_FAILURE);
	ft_printf("data->fd_pipe[0] = %i\n", data->fd_pipe[0]);
	ft_printf("data->fd_pipe[1] = %i\n", data->fd_pipe[1]);
	first_command(data);
	second_command(data);
	close (data->fd_pipe[0]);
	close (data->fd_pipe[1]);
	//REVIEW - estos waitpid estan correctos, el de pid[1] hay que hacer algo?
	waitpid(data->pid[0], &status[0], 0);
	executing_check(&status[0], 1);
	ft_printf("------------\nUn COMANDO ejecutado\n");
	waitpid(data->pid[1], &status[1], 0);
	ft_printf("CASI CASI Dos COMANDOS ejecutados\n");
	executing_check(&status[1], 2);
	ft_printf("Dos COMANDOS ejecutados\n");
	//close_fds(data);
	exit(WEXITSTATUS(status[1]));
}


//NOTE - Cambios hechos en la prueba:
//close fd_pipe en parent antes de los waitpid (en pipex.c 76, 77)
//redirigir el split de los argumentos a un nuevo puntero (en execute.c)
//EL PROBLEMA VIENE DE QUE AL CONCATENAR PATH SE ESTÁN SUMANDO LAS COMILLAS DE ARGV "LS"