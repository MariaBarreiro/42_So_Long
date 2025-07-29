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
	if (game->height < 3
		|| game->width < 3
		|| (game->height + game->width) <= 7)
		die(4, game);
	while (i < (game->height - 1))
	{
		if (modified_strlen(game->map[i]) != game->width
			&& game->map[i] != NULL)
			die(4, game);
		i++;
	}
}

void	check_borders(t_game *game)
{
	t_point_in_map	coords;

	coords.y = -1;
	while (++coords.y < game->height - 1)
	{
		if (coords.y == 0 || coords.y == game->height - 1)
		{
			coords.x = -1;
			while (++coords.x < game->width - 1)
			{
				if (game->map[coords.y][coords.x] != '1')
					die (5, game);
			}
		}
		else if (game->map[coords.y][0] != '1'
					|| game->map[coords.y][game->width - 1] != '1')
			die (5, game);
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
				die (7, game);
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
		die (7, game);
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
		die (7, game);
}
