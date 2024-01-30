/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:56:15 by crramire          #+#    #+#             */
/*   Updated: 2024/01/30 13:41:14 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* --- LIBRARIES --- */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <errno.h>
# include <fcntl.h>

/* ---------------- PATH ---------------- */
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"

/* ----- MESSAGES ----- */
# define USAGE "Usage: ./pipex infile cmd1 cmd2 outfile\n"


/* ----- CONSTANTS ----- */

enum e_fd_events{
	READ = 0,
	WRITE
};

enum e_exit_code{
	ERROR = 0,
	NO_ERROR = 1
};

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	*env_path;
	int		fd_infile;
	int		fd_outfile;
	char	*cmds[2];
	char	**cmd_args_splitted;
	int		fd_pipe[2];
	pid_t	pid[2];
}	t_pipex;

/* ----- STRUCT ----- */

/* ----- FUNCTIONS ----- */

#endif
