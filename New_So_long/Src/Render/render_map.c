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
	while(++game->coords.y < game->height)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->width)
		{
			put_walls(game, game->coords.x, game->coords.y);
			put_floor(game, game->coords.x, game->coords.y);
			put_rest(game, game->coords.x, game->coords.y);
			// render_tile(game, game->coords.x, game->coords.y);
		}
	}
}

void	put_walls(t_game *game, int x, int y)
{
	char coords;

	coords = game->map[y][x];
	while (coords)
	{
		put_image(game, game->textures.wall, x, y);
		coords++;
	}
}

void	put_floor(t_game *game, int x, int y)
{
	char coords;

	coords = game->map[y][x];
	while (coords)
	{
		put_image(game, game->textures.floor, x, y);
		coords++;
	}
}

void	put_rest(t_game *game, int x, int y)
{
	char	coords;
	void	*textures;

	coords =  game->map[y][x];
	textures = NULL;
	if (coords == 'C')
		textures = game->textures.collectible;
	else if (coords == 'P')
		textures = game->textures.idle_player;
	else if (coords == 'E')
		textures = select_exit(game);
	
	if (textures)
		put_image(game, textures, x, y);
}

void	put_image(t_game *game, void *img, int tile_x, int tile_y)
{
	int	pixel_x;
	int	pixel_y;

	if (!game->mlx_ptr || !game->mlx_win_ptr || !img)
	{
		printf("NULL pointer detected in put_image!\n");
		printf("mlx_ptr: %p\n", game->mlx_ptr);
		printf("mlx_win_ptr: %p\n", game->mlx_win_ptr);
		printf("img: %p\n", img);
		exit(1);
	}

	pixel_x = tile_x * SIZE;
	pixel_y = tile_y * SIZE;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win_ptr, img, pixel_x, pixel_y);
}
