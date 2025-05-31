/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:53:43 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/31 14:42:29 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(char *map_file, t_game *game)
{
	int	fd;

	///count lines to get the height
	game->height = count_lines(map_file);
	///error handling
	if(game->height <= 0)
	{
		printf("No lines!! Error needs handling!!(load_map)"); //FOR NOW
	}
	fd = open(map_file,O_RDONLY);
	//error handling
	if (fd <= 0)
	{
		printf("Couldnt open fd!!Error needs handling!! (load_map)");
	}
	//assign memory to the map
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	//error handling
	if (!game->map)
	{
		printf("Malloc to game->map didnt function!! Error needs handling!! (load_map)");
	}
	//fill the map
	fill_map(fd, game);
	//change width with modified strlen
	game->width = modified_strlen(game->map[0]);
	///close fd!!
	close(fd);
}

int count_lines(char *map_file)
{
	int		fd;
	int		i;
	char *	temp;

	i = 0;
	///Open map_file to return the fd that will identify it
	fd = open(map_file, O_RDONLY);
	//Error handling
	if (fd <= 0)
	{
		printf("Couldnt open fd!!Error needs handling!!(count_lines)");
		return (0); //FOR NOW;
	}
	///Read one row and store it
	temp = get_next_line(fd);
	///Free the row, read another one and increment the i (strlen for the height)
	while (temp != NULL)
	{
		i++;
		free(temp);
		temp = get_next_line(fd);
	}
	//close the fd and return the i
	close(fd);
	return (i);
}

void	fill_map(int fd, t_game *game)
{
	int	i;
	char	*read_rest;

	i = 0;
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	//read the fd until the end and free to avoid leaks
	read_rest=get_next_line(fd);
	free(read_rest);
	//NULL terminate the map
	game->map = NULL;
}

int	modified_strlen(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0' && map[i] != '\n' && map[i] != '\r')
		i++;
	return (i);
}
