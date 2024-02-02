/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:45:55 by crramire          #+#    #+#             */
/*   Updated: 2024/02/02 15:52:13 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/pipex.h"

void	ft_print_pids(pid_t pid)
{
	if (pid == 0)
		printf("Child PID = %i\n", pid);
	else
		printf("Daddy PID = %i\n", pid);
	return ;
}
