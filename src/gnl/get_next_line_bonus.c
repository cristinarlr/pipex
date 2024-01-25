/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:25:20 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/28 11:00:37 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char *stash)
{
	char	*line;
	char	*pnewline;
	int		line_len;

	if (stash[0] == '\0')
		return (NULL);
	if (ft_strchr(stash, '\n'))
	{
		pnewline = ft_strchr(stash, '\n') + 1;
		line_len = ft_strlen(stash) - ft_strlen(pnewline);
		line = ft_substr(stash, 0, line_len);
		if (!line)
			return (NULL);
	}
	else
		line = ft_strdup(stash);
	return (line);
}

static char	*ft_clean_stash(char *stash)
{
	char	*rest_stash;
	char	*pnewline;
	int		rest_stash_start;

	if (stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	if (ft_strchr(stash, '\n'))
	{
		pnewline = ft_strchr(stash, '\n') + 1;
		rest_stash_start = ft_strlen(stash) - ft_strlen(pnewline);
		rest_stash = ft_substr(stash, rest_stash_start, ft_strlen(pnewline));
		if (rest_stash == NULL)
		{
			free(stash);
			return (NULL);
		}
		free(stash);
		return (rest_stash);
	}
	free(stash);
	return (NULL);
}

static char	*ft_read_and_stock(int fd, char *stash)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	nbytes;

	*buff = '\0';
	nbytes = 1;
	while (!ft_strchr(stash, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (stash);
			return (0);
		}
		buff[nbytes] = '\0';
		stash = ft_strjoin(stash, buff);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!stash[fd])
			return (NULL);
		*stash[fd] = '\0';
	}
	stash[fd] = ft_read_and_stock(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract_line (stash[fd]);
	stash[fd] = ft_clean_stash(stash[fd]);
	return (line);
}

/* int main(int argc , char** argv)
{fra
	int		*fd;
	char	*line;
	char 	*files;
	_Bool 	cont = 1;
	int		max = 5;
	
    if (argc < 2)
        return 1;
	fd = malloc(sizeof(int *) * argc - 1);
	files = argv[1];
	
	int i = 1;
	while (i <= argc) {
		fd[i - 1] = open(argv[i], O_RDONLY);
		++i;
	}

	while (cont && max)
	{
		cont = 0;
		for (i = 1; i <= argc; ++i)
		{
			if ((line = get_next_line(fd[i - 1])))
			{
				printf("%i - '%s", fd[i - 1], line);
        		free(line);
			}
			cont |= (line != 0);
		}
	//	--max;
	}
//	close(fd);
	return (0);
}
 */