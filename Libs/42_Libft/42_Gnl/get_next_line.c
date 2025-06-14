/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:29:18 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/06 13:29:43 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_remaining(char *vault);
char	*ft_read_and_store(int fd, char *line, char *vault);
char	*ft_extract_line(char *vault, char *line);

char	*get_next_line(int fd)
{
	static char	vault[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (vault[0] && ft_strchr_gnl(vault, '\n'))
		return (ft_extract_line(vault, line));
	if (vault[0])
	{
		line = ft_strjoin_gnl(line, vault);
		if (!line)
			return (NULL);
	}
	line = ft_read_and_store(fd, line, vault);
	if (!line)
		return (NULL);
	line = ft_extract_line(vault, line);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_read_and_store(int fd, char *line, char *vault)
{
	char	*new_line;
	int		bytes_read;

	new_line = line;
	ft_remaining(vault);
	while (1)
	{
		bytes_read = read(fd, vault, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (line)
				free(line);
			ft_remaining(vault);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		new_line = ft_strjoin_gnl(new_line, vault);
		if (!new_line)
			return (NULL);
		if (ft_strchr_gnl(vault, '\n'))
			break ;
		ft_remaining(vault);
	}
	return (new_line);
}

char	*ft_extract_line(char *vault, char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	line = ft_strjoin_gnl(line, vault);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] != '\0')
		line[i] = '\0';
	ft_remaining(vault);
	return (line);
}

void	ft_remaining(char *vault)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (vault[i] != '\n' && vault[i])
		i++;
	if (vault[i] == '\n')
		i++;
	while (vault[i] != '\0')
	{
		vault[j] = vault[i];
		j++;
		i++;
	}
	while (j < BUFFER_SIZE)
	{
		vault[j] = '\0';
		j++;
	}
}
