/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:11:26 by mda-enca          #+#    #+#             */
/*   Updated: 2025/07/12 16:17:28 by mda-enca         ###   ########.fr       */
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
			render_corners(game, game->coords.x, game->coords.y);
			render_borders(game, game->coords.x, game->coords.y);
			render_tile(game, game->coords.x, game->coords.y);
		}
	}
}

void	render_corners(t_game *game, int x, int y)
{
	int	pixel_x = x * SIZE;
	int pixel_y = y * SIZE;

	if (y == 0 && x == 0)
		put_image(game, "../../Textures/walls/wall.xpm", pixel_x, pixel_y);
	if (y == game->height - 1 && x == game->width - 1)
		put_image(game, "../../Textures/walls/wall.xpm", pixel_x, pixel_y);
	if (y == 0 && x == game->width - 1)
		put_image(game, "../../Textures/walls/wall.xpm", pixel_x, pixel_y);
	if (y == game->height - 1 && x == 0)
		put_image(game, "../../Textures/walls/wall.xpm", pixel_x, pixel_y);
}

void	render_borders(t_game *game, int x, int y)
{
	int	pixel_x = x * SIZE;
	int pixel_y = y * SIZE;
	
	if (y == 0 && x < game->width - 1)
		put_image(game, "../../Textures/walls/wall.xpm", pixel_x, pixel_y);
	if (y > 0 && y < game->height - 1 && x == 0)
		put_image(game, "../../Textures/walls/wall.xpm", pixel_x, pixel_y);
	if (y > 0 && y < game->height - 1 && x == game->width - 1)
		put_image(game, "../../Textures/walls/wall.xpm", pixel_x, pixel_y);
	if (y == game->height - 1 && x > 0 && x < game->width - 1)
		put_image(game, "../../Textures/walls/wall.xpm", pixel_x, pixel_y);
}

void	render_tile(t_game *game, int x, int y)
{
	char	tile = game->map[y][x];
	int	pixel_x = x * SIZE;
	int pixel_y = y * SIZE;

	if (tile == '1' && y > 0 && y < game->height - 1
			&& x > 0 && x < game->width - 1)
		put_image(game, "../../Textures/walls/wall.xpm",pixel_x, pixel_y);
	if (tile == '0')
		put_image(game, "../../Textures/tile/floor.xpm",pixel_x, pixel_y);
	if (tile == 'P')
		put_image(game, "../../Textures/player/player.xpm",pixel_x, pixel_y);
	if (tile == 'C')
		put_image(game, "../../Textures/collect/coin.xpm",pixel_x, pixel_y);
	if (tile == 'E' && game->c_gathered != game->collectibles)
		put_image(game, "../../Textures/exit/inac.xpm",pixel_x, pixel_y);
	if (tile == 'E' && game->c_gathered == game->collectibles)
		put_image(game, "../../Textures/exit/exit.xpm",pixel_x, pixel_y);
}

void	put_image(t_game *game, char *tile, int tile_x, int tile_y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, tile, 
							   &game->tiles.x, &game->tiles.y);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win_ptr, 
						 game->img.mlx_img, tile_x, tile_y);
}
