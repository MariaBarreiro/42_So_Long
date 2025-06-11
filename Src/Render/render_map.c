/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:07:50 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/11 09:08:14 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	render_map(t_game *game)
{

}

void	put_image(t_game *game, void *img, int tile_x, int tile_y)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = tile_x * SIZE;
	pixel_y = tile_y * SIZE;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win_ptr, img, tile_x, tile_y);
}

void	render_tile(t_game *game, int x, int y)
{
	char coords;

	coords = game->map[y][x];
	if (coords == '1')
		put_image(game, select_water(game, x, y), x, y);
	if (coords != '1')
		put_image(game, select_grass(game, x, y), x, y);
	if (coords == 'C')
		put_image(game, game->textures.collectible, x, y);
}
