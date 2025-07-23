/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:17:46 by mda-enca          #+#    #+#             */
/*   Updated: 2025/07/23 09:38:09 by mda-enca         ###   ########.fr       */
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
		}
	}
}

void	put_walls(t_game *game, int x, int y)
{
	char coords;

	coords = game->map[y][x];
	if (coords == '1')
		put_image(game, "../../Textures/walls/wall.xpm", x, y);
}

void	put_floor(t_game *game, int x, int y)
{
	char	coords;

	coords = game->map[y][x];
	if (coords == '0')
		put_image(game, "../../Textures/tile/floor.xpm", x, y);
}

void	put_rest(t_game *game, int x, int y)
{
	char	coords;
	void	*textures;

	coords =  game->map[y][x];
	textures = NULL;
	if (coords == 'C')
		textures = "../../Textures/collect/coin.xpm";
	else if (coords == 'P')
		textures = "../../Textures/player/player.xpm";
	else if (coords == 'E' && game->c_gathered != game->collectibles)
		textures = "../../Textures/exit/inac.xpm";
	else if (coords == 'E' && game->c_gathered == game->collectibles)
		textures = "../../Textures/exit/exit.xpm";

	if (textures)
		put_image(game, textures, x, y);
}

// void	put_image(t_game *game, void *img, int tile_x, int tile_y)
// {
// 	int	pixel_x;
// 	int	pixel_y;
//
// 	if (!game->mlx_ptr || !game->mlx_win_ptr || !img)
// 	{
// 		printf("NULL pointer detected in put_image!\n");
// 		printf("mlx_ptr: %p\n", game->mlx_ptr);
// 		printf("mlx_win_ptr: %p\n", game->mlx_win_ptr);
// 		printf("img: %p\n", img);
// 		exit(1);
// 	}
//
// 	pixel_x = tile_x * SIZE;
// 	pixel_y = tile_y * SIZE;
// 	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win_ptr, img, pixel_x, pixel_y);
// }
//
void	put_image(t_game *game, char *tile, int tile_x, int tile_y)
{
	// if (game->img.mlx_img)
	// {
	// 	mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	// 	game->img.mlx_img = 0;
	// }
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, tile, 
							   &game->tiles.x, &game->tiles.y);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win_ptr, 
						 game->img.mlx_img, tile_x, tile_y);
}
