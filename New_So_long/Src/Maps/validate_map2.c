/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:23:44 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/15 17:43:12 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

///check if all collectibles and exit are reachable from the player position

void	check_valid_path(t_game *game)
{
	char	**cpy_map;

	cpy_map = (char **)malloc(sizeof(char *) * game->height);
	if (!cpy_map)
		die(6, game);
	while (++game->coords.y < game->height)
		cpy_map[game->coords.y] = ft_strdup (game->map[game->coords.y]);
	flood_fill(cpy_map, game, game->player.y, game->player.x);
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
	if (x < 0 || y < 0 || x >= game->width - 1 || y >= game->height - 1)
		return ;
	if (cpy_map[y][x] == 'F' || cpy_map[y][x] == '1')
		return ;
	if (cpy_map[y][x] == 'C')
	{
		cpy_map[y][x] = 'F';
		game->c_gathered += 1;
	}
	if (cpy_map[y][x] == 'E')
	{
		cpy_map[y][x] = 'F';
		game->e_reached = 1;
		return ;
	}
	if (cpy_map[y][x] == '0')
		cpy_map[y][x] = 'F';
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
