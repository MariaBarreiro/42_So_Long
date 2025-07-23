// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   load_textures.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/07/23 09:23:32 by mda-enca          #+#    #+#             */
// /*   Updated: 2025/07/23 09:27:18 by mda-enca         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
//
// #include "../../Includes/so_long.h"
//
// void	load_textures(t_game *game)
// {
// 	game->tiles.y = SIZE;
// 	game->tiles.x = SIZE;
// 	
// 	game->textures.collectible
// 		= mlx_xpm_file_to_image(game->mlx_ptr, "../../Textures/collect/coin.xpm",
// 		&game->tiles.x, &game->tiles.y);
// 	game->textures.exit_active
// 		= mlx_xpm_file_to_image(game->mlx_ptr, "../../Textures/exit/exit.xpm",
// 			&game->tiles.x, &game->tiles.y);
// 	game->textures.exit_inactive
// 		= mlx_xpm_file_to_image(game->mlx_ptr, "../../Textures/exit/inac.xpm",
// 			&game->tiles.x, &game->tiles.y);
// 	game->textures.idle_player
// 		= mlx_xpm_file_to_image(game->mlx_ptr, "../../Textures/player/player.xpm",
// 			&game->tiles.x, &game->tiles.y);
// 	game->textures.wall
// 		= mlx_xpm_file_to_image(game->mlx_ptr, "../../Textures/walls/wall.xpm",
// 			&game->tiles.x, &game->tiles.y);
// 	game->textures.floor
// 		= mlx_xpm_file_to_image(game->mlx_ptr, "../../Textures/tile/floor.xpm",
// 			&game->tiles.x, &game->tiles.y);
// }
