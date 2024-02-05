/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:45:55 by crramire          #+#    #+#             */
/*   Updated: 2024/02/05 11:01:03 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
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
