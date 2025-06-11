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

void	*select_grass_combinations(t_game *game, int x, int y)
{
	char	**map;
	int		up;
	int		down;
	int		left;
	int		right;

	map = game->map;
	up = y > 0 && map[y - 1][x] == '1';
	down = y < (game->height - 1) && map[y + 1][x] == 1;
	left = x > 0 && map[x - 1][y] == '1';
	right = x < (game->width - 1) && map[y][x + 1] == 1;
	if (up == 1 && left == 1)
		return (game->textures.grass_b_lft_up);
	else if (down == 1 && left == 1)
		return (game->textures.grass_b_lft_dwn);
	else if (right == 1 && up == 1)
		return (game->textures.grass_b_rght_up);
	else if (right == 1 && down == 1)
		return (game->textures.grass_b_rght_dwn);
}
