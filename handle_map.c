/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:53:43 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/31 09:55:05 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gnl/get_next_line.h"
#include "so_long.h"
#include <fcntl.h>

void	load_map(char *map_file, t_game *game)
{
	///count lines to get the height
	game->height = count_lines(map_file);

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
