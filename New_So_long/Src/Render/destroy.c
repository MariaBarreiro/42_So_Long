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
	mlx_destroy_image(game->mlx_ptr, "../../Textures/collect/coin.xpm");
	mlx_destroy_image(game->mlx_ptr, "../../Textures/exit/exit.xpm");
	mlx_destroy_image(game->mlx_ptr, "../../Textures/exit/inac.xpm");
	mlx_destroy_image(game->mlx_ptr, "../../Textures/player/player.xpm");
	mlx_destroy_image(game->mlx_ptr, "../../Textures/tile/floor.xpm");
	mlx_destroy_image(game->mlx_ptr, "../../Textures/walls/wall.xpm");
}
