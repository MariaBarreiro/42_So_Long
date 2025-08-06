/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:07:50 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/15 18:18:46 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	render_map(t_game *game)
{
	game->coords.y = -1;
	while (++game->coords.y < game->height)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->width)
		{
			put_walls(game, game->coords.x, game->coords.y);
			put_floor(game, game->coords.x, game->coords.y);
			put_rest(game, game->coords.x, game->coords.y);
		}
	}
}

void	put_walls(t_game *game, int x, int y)
{
	char	coords;

	coords = game->map[y][x];
	if (coords == '1')
		put_image(game, game->textures.wall, x, y);
}

void	put_floor(t_game *game, int x, int y)
{
	char	coords;

	coords = game->map[y][x];
	if (coords == '0')
		put_image(game, game->textures.floor, x, y);
}

void	put_rest(t_game *game, int x, int y)
{
	char	coords;
	void	*textures;

	coords = game->map[y][x];
	textures = NULL;
	if (coords == 'C')
		textures = game->textures.collectible;
	else if (coords == 'P')
		textures = game->textures.idle_player;
	else if (coords == 'E' && game->c_gathered != game->collectibles)
		textures = game->textures.exit_inactive;
	else if (coords == 'E' && game->c_gathered == game->collectibles)
		textures = game->textures.exit_active;
	if (textures)
		put_image(game, textures, x, y);
}

void	put_image(t_game *game, void *img, int tile_x, int tile_y)
{
	int	x;
	int	y;

	x = tile_x * SIZE;
	y = tile_y * SIZE;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win_ptr, img, x, y);
}
