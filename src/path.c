/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:56 by Cristina          #+#    #+#             */
/*   Updated: 2024/03/12 12:36:15 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

//gets and stores path info from envp
char	*find_path_in_envp(t_pipex *data)
{
	int	i;

	//ft_printf("Dentro de find_path_in_envp\n");
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
		exit_program(NO_CMD, data);
	if (cmd[0] == '.' | cmd[0] == '/')
	{
		if (access(data->argv[2], F_OK & R_OK & X_OK) == 0)
			return (1);
		else
			exit_program(CMD, data);
	}
	return (0);
}

//get command in route format "/../../cmd"
//? cmd_path should be freed after future use?
char	*get_cmd_path_route(t_pipex *data, char *cmd)
{
	int		i;
	char	*add_slash;
	char	*cmd_path;

	i = 0;
	if (check_command_type(data, cmd) == 1)
		return (cmd);
	else
	{
		//ft_printf("get_cmd_path_route: cmd = %s\n", cmd);
		data->envp_path_splitted = ft_split(data->envp_path, ':');
		while (data->envp_path_splitted[i])
		{
			add_slash = ft_strjoin(data->envp_path_splitted[i], "/");
			if (!add_slash)
				return (NULL);
			cmd_path = ft_strjoin(add_slash, cmd);
			free(add_slash);
			if (access(cmd_path, F_OK) == 0)
				return (cmd_path);
			i++;
		}
	}
	return (NULL);
}
