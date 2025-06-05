/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:35:19 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/31 18:50:56 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

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
		printf("%d", modified_strlen(game->map[i]));
		if (modified_strlen(game->map[i]) != game->width && game->map[i] != NULL)
			printf("map not a rectangle!!Error needs handling!! (check map size)");
		i++;
	}
}

void check_borders(t_game *game)
{
	t_point_in_map	coords;

	coords.y = -1;
	while (++coords.y < game->height)
	{
		if (coords.y == 0 || coords.y == game->height - 1)
		{
			coords.x = -1;
			while (++coords.x < game->width - 1)
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

void	check_map_assets(t_game *game)
{
	t_point_in_map	coords;

	coords.y = -1;
	while (++coords.y < (game->height - 1))
	{
		coords.x = -1;
		while (game->map[coords.y][++coords.x] != '\0')
		{
			if (game->map[coords.y][coords.x] != '0'
				&& game->map[coords.y][coords.x] != '1'
				&& game->map[coords.y][coords.x] != 'P'
				&& game->map[coords.y][coords.x] != 'E'
				&& game->map[coords.y][coords.x] != 'C')
				printf("Wrong chars on the map!!!! Error needs handling!! (check_map_assets)");
		}
	}
}

void	count_assets(t_game *game)
{
	t_point_in_map				coords;
	int							player;
	int							exit;

	player = 0;
	exit = 0;
	coords.y = -1;
	while (++coords.y < (game->height - 1))
	{
		coords.x = -1;
		while (++coords.x < (game->width - 1))
		{
			if (game->map[coords.y][coords.x] == 'P')
				player += 1;
			else if (game->map[coords.y][coords.x] == 'E')
				exit += 1;
		}
	}
	if (player != 1 || exit != 1)
		printf("More than one player or exit!! Error needs handling!! (count_assets)");
}

void	check_map_content(t_game *game)
{
	t_point_in_map	coords;

	coords.y = -1;
	while (++coords.y < (game->height - 1))
	{
		coords.x = -1;
		while (++coords.x < (game->width - 1))
		{
			if (game->map[coords.y][coords.x] == 'P')
				game->player = coords;
			else if (game->map[coords.y][coords.x] == 'E')
				game->exit = coords;
			else if (game->map[coords.y][coords.x] == 'C')
				game->collectibles += 1;
		}
	}
	if (game->collectibles <= 0)
		printf("No collectibles!! Invalid Map!! Error needs handling!! (check_map_content)");
}
