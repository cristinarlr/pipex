/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:56 by Cristina          #+#    #+#             */
/*   Updated: 2024/02/01 13:08:00 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/pipex.h"

char	*find_path_in_envp(t_pipex *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (ft_strnstr(data->envp[i], "PATH=", 5) != 0)
		{
			data->envp_path = ft_strnstr(data->envp[i], "PATH=", 5);
			return (data->envp_path);
		}
		i++;
	}
	return (0);
}

int	check_command(t_pipex *data, char cmd)
{
	if (data->argv[2][0] == '.' | data->argv[2][0] == '/')
		access(data->argv[2], F_OK);

}

char	*get_cmd_path_routes(t_pipex *data, char *cmd)
{
	int		i;
	char	*cmd_route;

	//check if cmd passed is a route
	if (check_command(data, cmd) == 1)
		return (cmd);
	//else build command route
	data->envp_path_splitted = ft_split(data->envp_path, ':');


}
