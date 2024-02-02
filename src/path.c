/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:56 by Cristina          #+#    #+#             */
/*   Updated: 2024/02/02 12:59:00 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/pipex.h"

//gets and stores path info from envp
char	*find_path_in_envp(t_pipex *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (ft_strnstr(data->envp[i], "PATH=", 5) != 0)
		{
			data->envp_path = ft_strnstr(data->envp[i], "PATH=", 5) + 5;
			return (data->envp_path);
		}
		i++;
	}
	return (0);
}

//check if cmd passed is a route
static int	check_command_type(t_pipex *data, char *cmd)
{
	if (ft_strlen(data->argv[2]) == 0 | ft_strlen(data->argv[3]) == 0)
		exit(ft_printf("crear función exit_program - invalid arguments"));
	if (cmd[0] == '.' | cmd[0] == '/')
	{
		if (access(data->argv[2], F_OK & R_OK & X_OK) == 0)
			return (1);
		else
			exit(ft_printf("crear función exit_program - invalid PATH input"));
	}
	return (0);
}

char	*get_cmd_path_route(t_pipex *data, char *cmd_route)
{
	int		i;
	char	*add_slash;

	i = 0;
	if (check_command_type(data, cmd_route) == 1)
		return (cmd_route);
	else
	{
		data->envp_path_splitted = ft_split(data->envp_path, ':');
		while (data->envp_path_splitted[i])
		{
			add_slash = ft_strjoin(data->envp_path_splitted[i], "/");
			cmd_route = ft_strjoin(add_slash, cmd_route);
			//ft_printf("cmd_route (%i) = %s\n", i, cmd_route);
			i++;
		}
	}
	return (cmd_route);
}
