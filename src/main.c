/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:59 by crramire          #+#    #+#             */
/*   Updated: 2024/01/26 14:19:43 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd3_infile;
	int	fd4_outfile;

	fd3_infile = open(argv[1], O_RDONLY);
	fd4_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd3_infile < 0 || fd4_outfile < 0)
		return (-1);
	//pipex(fd3_infile, fd4_outfile, argc, envp);
	return (0);
}
