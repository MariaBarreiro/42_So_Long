/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:41:13 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/11 11:51:10 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	destroy_textures(t_game *game)
{
	destroy_grass(game);
	destroy_walls(game);
	destroy_rest(game);
}

void	destroy_grass(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->textures.grass);
	mlx_destroy_image(game->mlx_ptr, game->textures.grass_b_up);
	mlx_destroy_image(game->mlx_ptr, game->textures.grass_b_lft);
	mlx_destroy_image(game->mlx_ptr, game->textures.grass_b_dwn);
	mlx_destroy_image(game->mlx_ptr, game->textures.grass_b_rght);
	mlx_destroy_image(game->mlx_ptr, game->textures.grass_b_rght_up);
	mlx_destroy_image(game->mlx_ptr, game->textures.grass_b_rght_dwn);
}

void	destroy_walls(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->textures.surrounded_by_water);
	mlx_destroy_image(game->mlx_ptr, game->textures.water);
	mlx_destroy_image(game->mlx_ptr, game->textures.water_b_rght);
	mlx_destroy_image(game->mlx_ptr, game->textures.water_b_lft);
	mlx_destroy_image(game->mlx_ptr, game->textures.water_from_up_dwn);
	mlx_destroy_image(game->mlx_ptr, game->textures.water_from_lft_rght);	
}

void	destroy_rest(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->textures.collectible);
	mlx_destroy_image(game->mlx_ptr, game->textures.exit_active);
	mlx_destroy_image(game->mlx_ptr, game->textures.exit_inactive);
	mlx_destroy_image(game->mlx_ptr, game->textures.idle_player);
	mlx_destroy_image(game->mlx_ptr, game->textures.left_player);
	mlx_destroy_image(game->mlx_ptr, game->textures.right_player);	
}
