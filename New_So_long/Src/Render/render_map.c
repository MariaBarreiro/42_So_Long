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
			// put_walls(game, game->coords.x, game->coords.y);
			// put_floor(game, game->coords.x, game->coords.y);
			// put_rest(game, game->coords.x, game->coords.y);
			render_corners(game, game->coords.x, game->coords.y);
			render_tile(game, game->coords.x, game->coords.y);
		}
	}
}

void	render_corners(t_game *game, int x, int y)
{
	if (y == 0 && x == 0)
		put_image(game, game->textures.wall, x * SIZE, y * SIZE);
	if (y == game->height - 1 && x == 0)
		put_image(game, game->textures.wall, x * SIZE, y * SIZE);
	if (y == 0 && x == game->width - 1)
		put_image(game, game->textures.wall, x * SIZE, y * SIZE);
	if (y == game->height - 1 && x == game->width - 1)
		put_image(game, game->textures.wall, x * SIZE, y * SIZE);
}

void	render_tile(t_game *game, int x, int y)
{
	char coords;

	coords = game->map[y][x];
	// if (coords == '1' && y > 0 && y < game->height - 1 
	// 	&& x > 0 && x < game->width - 1)
	if (coords == '1')
		put_image(game, game->textures.wall, x * SIZE, y * SIZE);
	if (coords == '0')
		put_image(game, game->textures.floor, x * SIZE, y * SIZE);
	if (coords == 'P')
		put_image(game, game->textures.idle_player, x * SIZE, y * SIZE);
	if (coords == 'C')
		put_image(game, game->textures.collectible, x * SIZE, y * SIZE);
	if (coords == 'E' && game->c_gathered == game->collectibles
			&& game->e_reached == 1)
		put_image(game, game->textures.exit_active, x * SIZE, y * SIZE);
	if (coords == 'E' && game->c_gathered != game->collectibles
			&& game->e_reached == 0)
		put_image(game, game->textures.exit_inactive, x * SIZE, y * SIZE);
}

void	put_image(t_game *game, char *tile, int tile_x, int tile_y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	printf("%p", game->img.mlx_img);
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, tile, &game->tiles.x, &game->tiles.y);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win_ptr, game->img.mlx_img, tile_x, tile_y);
}
//
// void	put_walls(t_game *game, int x, int y)
// {
// 	char coords;
//
// 	coords = game->map[y][x];
// 	if (coords == '1')
// 	{
// 		put_image(game, game->textures.wall, x, y);
// 		coords++;
// 	}
// }
//
// void	put_floor(t_game *game, int x, int y)
// {
// 	char coords;
//
// 	coords = game->map[y][x];
// 	if (coords == '0')
// 	{
// 		put_image(game, game->textures.floor, x, y);
// 		coords++;
// 	}
// }
//
// void	put_rest(t_game *game, int x, int y)
// {
// 	char	coords;
// 	void	*textures;
//
// 	coords =  game->map[y][x];
// 	textures = NULL;
// 	if (coords == 'C')
// 		textures = game->textures.collectible;
// 	else if (coords == 'P')
// 		textures = game->textures.idle_player;
// 	else if (coords == 'E')
// 		textures = select_exit(game);
// 	
// 	if (textures)
// 		put_image(game, textures, x, y);
// }
//
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
// 	
// 	if (game->img.mlx_img)
// 	{
// 		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
// 		game->img.mlx_img = 0;
// 	}
// 	game->img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.mlx_img, &game->tiles.x, &game->tiles.y);
// 	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win_ptr, img, pixel_x, pixel_y);
// }
