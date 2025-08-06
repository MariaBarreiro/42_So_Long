/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:07 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/03 14:29:38 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

t_game	*init(t_game *game)
{
	// t_game	*game;
	//
	// game = (t_game *)malloc(1 * sizeof(t_game));
	// if (!game)
	// 	die(6, game);
	init_game(game);
	init_mlx(game);
//	load_textures(game);
	return (game);
}

void	init_game(t_game *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->collectibles = 0;
	game->c_gathered = 0;
	game->e_reached = 0;
	game->moves = 0;
	game->coords.y = -1;
	game->coords.x = -1;
	game->player.y = 0;
	game->player.x = 0;
	game->exit.y = 0;
	game->exit.x = 0;
}

void	init_mlx(t_game *game)
{
	// game->mlx_ptr = mlx_init();
	game->mlx_ptr =  NULL;
	game->mlx_win_ptr = NULL;
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_len = 0;
	game->img.endian = 0;
	game->tiles.y = SIZE;
	game->tiles.x = SIZE;
}
