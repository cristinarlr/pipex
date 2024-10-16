/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:56:15 by crramire          #+#    #+#             */
/*   Updated: 2024/03/12 10:51:34 by crramire         ###   ########.fr       */
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
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

/* ---------------- PATH ---------------- */
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"

/* ----- MESSAGES ----- */
# define USAGE "Usage: ./pipex infile cmd1 cmd2 outfile\n"

/* ----- CONSTANTS ----- */

enum e_fd_stream
{
	INFILE = 0,
	OUTFILE
};

enum e_fd_events
{
	READ = 0,
	WRITE
};

enum e_child_process
{
	CHILD = 0,
};

enum e_exit_code
{
	ERROR = 0,
	NO_ERROR = 1
};

typedef enum s_error
{
	ENV = 0,
	FILE_ERR,
	NO_CMD,
	CMD,
	MALLOC,
	FORK,
	EXECVE
}	t_error;

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	*cmds[2];
	int		fd_infile;
	int		fd_outfile;
	int		fd_pipe[2];
	char	*envp_path;
	char	**envp_path_splitted;
	char	**cmd_args_splitted;
	pid_t	pid[2];
}	t_pipex;

/* ----- STRUCT ----- */

/* ----- FUNCTIONS ----- */
char	*find_path_in_envp(t_pipex *data);
char	*get_cmd_path_route(t_pipex *data, char *cmd);
int		pipex(t_pipex *data);
void	ft_print_pids(pid_t pid);
void	ft_print_array(char **arr);
void	exec_cmd_1(t_pipex *data);
void	exec_cmd_2(t_pipex *data);
void	exit_program(t_error code, t_pipex *data);
void	close_fds(t_pipex *data);

/* ----- FUNCTIONS (UTILS) ----- */
void	executing_check(int *status, int command);
void	ft_print_pids(pid_t pid);

#endif
