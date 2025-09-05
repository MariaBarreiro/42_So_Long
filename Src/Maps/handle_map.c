/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:53:43 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/31 18:24:59 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	load_map(char *map_file, t_game *game)
{
	int	fd;

	game->height = count_lines(map_file);
	if (game->height <= 0)
		die (4, game);
	fd = open (map_file, O_RDONLY);
	if (fd <= 0)
		die(1, game);
	game->map = (char **)malloc(sizeof(char *) * (game->height));
	if (!game->map)
		die(6, game);
	fill_map(fd, game);
//	game->map[game->height] = NULL;
	game->width = modified_strlen(game->map[0]);
	close(fd);
}

int	count_lines(char *map_file)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		die(1, NULL);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		i++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	fill_map(int fd, t_game *game)
{
	int		i;
	char	*read_rest;

	i = -1;
	while (++i < game->height)
	{
		game->map[i] = get_next_line(fd);
	}
	read_rest = get_next_line(fd);
	free(read_rest);
}

int	modified_strlen(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0' && map[i] != '\n' && map[i] != '\r')
		i++;
	return (i);
}
