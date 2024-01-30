/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:59 by crramire          #+#    #+#             */
/*   Updated: 2024/01/29 13:37:55 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc != 5)
		return (write(1, USAGE, 40));
	pipex(data);
	/* data.infile = open(argv[1], O_RDONLY);
	data.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data.infile < 0 || data.outfile < 0)
		return (-1);
	//pipex(fd3_infile, fd4_outfile, argc, envp); */
	return (0);
}
