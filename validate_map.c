/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:35:19 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/31 18:24:18 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validation(t_game *game)
{
	check_map_size(game);
	check_borders(game);
	check_map_content(game);
}

void	check_map_size(t_game *game)
{
	int	i;

	i = 0;
	//minimum size check
	if (game->height < 3 || game->width < 3 || (game->height + game->width) <= 7)
		printf("Minimum size not met! Error needs handling! (check_map_size)");
	//because its an array and it starts at 0, I need to take one value of Height!!!!!!!
	while (i < (game->height - 1))
	{
		//rectangle check
		if (modified_strlen(game->map[i]) != game->width && game->map[i] != NULL)
			printf("map not a rectangle!!Error needs handling!! (check map size)");
		i++;
	}
}

void check_borders(t_game *game)
{
	t_point_in_map	coords;

	coords.y = 0;
	while (coords.y++ < game->height)
	{
		if (coords.y == 0 || coords.y == game->height - 1)
		{
			coords.x = 0;
			while (coords.x++ < game->width - 1)
			{
				if (game->map[coords.y][coords.x] != '1')
					printf("the map is not valid!! Error needs handling! (check_borders)");
			}
		}
		else if (game->map[coords.y][0] != '1' 
					|| game->map[coords.y][game->width - 1] != '1')
					printf("the map is not valid!! Error needs handling! (check_borders)");
	}
}

void	count_assets(t_game *game)
{
	t_point_in_map	coords;
	int							player;
	int							exit;

	player = 0;
	exit = 0;
	coords.y. = 0;
	while (coords.y++ < (game->height - 1))
	{
	}
}

void	check_map_content(t_game *game)
{
	t_point_in_map	coords;

	coords.y = 0;
	while (coords.y++ < (game->height - 1))
	{
		coords.x = 0;
		while (coords.x++ < (game->width - 1))
		{
			if (game->map[coords.y][coords.x] == 'P')
				game->player = coords;
			else if (game->map[coords.y][coords.x] == 'E')
				game->exit = coords;
			else if (game->map[coords.y][coords.x] == 'C')
				game->collectibles += 1;
		}
	}
}
