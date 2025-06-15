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
	while(++game->coords.y < game->height)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->width)
			render_tile(game, game->coords.x, game->coords.y);
	}
}

void	put_image(t_game *game, void *img, int tile_x, int tile_y)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = tile_x * SIZE;
	pixel_y = tile_y * SIZE;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win_ptr, img, pixel_x, pixel_y);
}

void	render_tile(t_game *game, int x, int y)
{
	char coords;

	coords = game->map[y][x];
	if (coords == '1')
		put_image(game, select_water(game, x, y), x, y);
	else if (coords != '1')
		put_image(game, select_grass(game, x, y), x, y);
	else if (coords == 'C')
		put_image(game, game->textures.collectible, x, y);
	else if (coords == 'P')
		return ;
	else if (coords == 'E')
		put_image(game, select_exit(game), x, y);
}
