/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:23:44 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/03 13:23:46 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

///check if all collectibles (c) and exit (e) are reachable from the player position

void	check_valid_path(t_game *game)
{
	char	**cpy_map;

	cpy_map = (char **)malloc(sizeof(char *) * game->height);
	if (!cpy_map)
		die(6, game);
	///cpy each row into cpy_map
	while (++game->coords.y < game->height)
		cpy_map[game->coords.y] = ft_strdup (game->map[game->coords.y]);
	///run the cpy_map and update visited tiles with 'F'
	flood_fill(cpy_map, game, game->player.x, game->player.y);
	///loop through the cpy_map again to look for unreachable assets
	game->coords.y = -1;
	while (++game->coords.y < game->height)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->width)
		{
			if (cpy_map[game->coords.y][game->coords.x] == 'C'
				|| cpy_map[game->coords.y][game->coords.x] == 'E')
			{
				free_array (cpy_map, game->height);
				die (9, game);
			}
		}
	}
	free_array (cpy_map, game->height);
}

///Run the cpy_map, update visited tiles with 'F' and track reached 'c' and 'e';

void	flood_fill(char **cpy_map, t_game *game, int y, int x)
{
	///check if the player is outside the cpy_map
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	///check if coords in cpy_map were already visited (F -> filled) or if its a wall (1)
	if (cpy_map[y][x] == 'F' || cpy_map[y][x] == '1')
		return ;
	///handle how many collectibles exist
	if (cpy_map[y][x] == 'C')
	{
		cpy_map[y][x] = 'F';
		game->c_gathered += 1;
	}
	///if were at the exit but we still haven't collected all collectibles
	if (cpy_map[y][x] == 'E' && game->collectibles != game->c_gathered)
	{
		cpy_map[y][x] = 'F';
		game->e_reached = 1;
		return ;
	}
	if (cpy_map[y][x] == '0')
		cpy_map[y][x] = 'F';
	///Recursive calls to read the cpy_map! It will change it gradually to all 'F' (filled)
	flood_fill(cpy_map, game, y, (x + 1));
	flood_fill(cpy_map, game, (y + 1), x);
	flood_fill(cpy_map, game, y, (x - 1));
	flood_fill(cpy_map, game, (y - 1), x);
}

void	final_check(t_game *game)
{
	if (game->collectibles != game->c_gathered
		|| game->e_reached != 1)
		die (7, game);
}
