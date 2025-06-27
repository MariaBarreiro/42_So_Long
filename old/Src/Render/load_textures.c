/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:47:19 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/11 10:50:25 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	load_textures(t_game *game)
{
	game->tiles.y = SIZE;
	game->tiles.x = SIZE;
	load_grass(game);
	load_walls(game);
	load_rest(game);
}
void	load_grass(t_game *game)
{
	game->textures.grass
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/g.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.grass_b_up
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/g_b_u.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.grass_b_lft
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/g_b_l.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.grass_b_dwn
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/g_b_d.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.grass_b_rght
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/g_b_r.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.grass_b_rght_up
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/g_b_ru.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.grass_b_rght_dwn
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/g_b_rd.xpm",
			&game->tiles.x, &game->tiles.y);
}

void	load_walls(t_game *game)
{
	game->textures.surrounded_by_water
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/s_by_w.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.water
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/walls/Water.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.water_b_rght
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/w_b_r.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.water_b_lft
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/w_b_l.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.water_from_up_dwn
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/w_f_ud.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.water_from_lft_rght
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/tile/w_f_lr.xpm",
			&game->tiles.x, &game->tiles.y);
}

void	load_rest(t_game *game)
{
	game->textures.collectible
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/collect/c.xpm",
		&game->tiles.x, &game->tiles.y);
	game->textures.exit_active
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/exit/ac.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.exit_inactive
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/exit/inac.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.idle_player
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/player/i.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.left_player
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/player/l.xpm",
			&game->tiles.x, &game->tiles.y);
	game->textures.right_player
		= mlx_xpm_file_to_image(game->mlx_ptr, "Textures/player/r.xpm",
			&game->tiles.x, &game->tiles.y);
}
