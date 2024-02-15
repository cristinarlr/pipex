/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:45:55 by crramire          #+#    #+#             */
/*   Updated: 2024/02/15 12:22:51 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_print_pids(pid_t pid)
{
	ft_printf("************************\n");
	if (pid == 0)
		ft_printf("Child PID = %i\n", pid);
	else
		ft_printf("Daddy PID = %i\n", pid);
	ft_printf("************************\n");
	return ;
}

void	ft_print_array(char **arr)
{
	int	i;

	ft_printf("Dentro de print_array\n");
	i = 0;
	while (arr[i])
	{
		ft_printf("arr[%i] = %s\n", i, arr[i]);
		i++;
	}
	ft_printf("Dentro de print_array\n");
}
