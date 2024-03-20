/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:45:55 by crramire          #+#    #+#             */
/*   Updated: 2024/03/20 09:54:51 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	ft_print_pids(pid_t pid)
{
	if (pid == 0)
		ft_printf("Child PID = %i\n", pid);
	else
		ft_printf("Daddy PID = %i\n", pid);
	return ;
}

void	ft_print_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf("arr[%i] = %s\n", i, arr[i]);
		i++;
	}
	ft_printf("arr[%i] = %s\n", i, arr[i]);
}

void	executing_check(int *status, int command)
{
	int	status_code;

	status_code = 0;
	if (WIFEXITED(*status))
	{
		ft_printf("..............inside executing_check Command %i\n", command);
		status_code = WEXITSTATUS(status[0]);
		if (status_code == 0)
			ft_printf(".............. ✅ SUCCES Command %i\n", command);
		else
			ft_printf(".............. 🔥 FAILURE Command %i with statusCode %d\n", command, status_code);
	}
}
