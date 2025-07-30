/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:21:48 by mda-enca          #+#    #+#             */
/*   Updated: 2025/07/23 09:23:07 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	destroy_textures(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->textures.collectible);
	mlx_destroy_image(game->mlx_ptr, game->textures.exit_active);
	mlx_destroy_image(game->mlx_ptr, game->textures.exit_inactive);
	mlx_destroy_image(game->mlx_ptr, game->textures.idle_player);
	mlx_destroy_image(game->mlx_ptr, game->textures.floor);
	mlx_destroy_image(game->mlx_ptr, game->textures.wall);
}
