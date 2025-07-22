/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:33:49 by mda-enca          #+#    #+#             */
/*   Updated: 2025/07/12 16:40:25 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	move_up(t_game *game)
{
	int		previous_pos;
	int		new_pos;
	int		x_pos;
	void	*old_floor;

	previous_pos = game->player.y;
	new_pos = game->player.y - 1;
	x_pos = game->player.x;
	old_floor = game->textures.floor;

	//restore correct floor at old position
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	//2/3 missing in new tile
	put_image(game, game->textures.idle_player, (x_pos * SIZE), 
		   new_pos * (SIZE - ((SIZE / 3) * 1)));
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	//1/3 missing in new tile
	put_image(game, game->textures.idle_player, (x_pos * SIZE), 
		   new_pos * (SIZE - ((SIZE / 3) * 2)));
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));
	
	//new tile
	put_image(game, game->textures.idle_player, (x_pos * SIZE), 
		   new_pos * SIZE);
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	game->player.y = new_pos;
	//falta checkar se ganhei o jogo
}

void	move_down(t_game *game)
{
	int		previous_pos;
	int		new_pos;
	int		x_pos;
	void	*old_floor;

	previous_pos = game->player.y;
	new_pos = game->player.y + 1;
	x_pos = game->player.x;
	old_floor = game->textures.floor;

	//restore correct floor at old position
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	//2/3 missing in new tile
	put_image(game, game->textures.idle_player, (x_pos * SIZE), 
		   new_pos * (SIZE + ((SIZE / 3) * 1)));
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	//1/3 missing in new tile
	put_image(game, game->textures.idle_player, (x_pos * SIZE), 
		   new_pos * (SIZE + ((SIZE / 3) * 2)));
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));
	
	//new tile
	put_image(game, game->textures.idle_player, (x_pos * SIZE), 
		   new_pos * SIZE);
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	game->player.y = new_pos;
	//falta checkar se ganhei o jogo
}

void	move_right(t_game *game)
{
	int		previous_pos;
	int		new_pos;
	int		y_pos;
	void	*old_floor;

	previous_pos = game->player.x;
	new_pos = game->player.x + 1;
	y_pos = game->player.y;
	old_floor = game->textures.floor;

	//restore correct floor at old position
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	//2/3 missing in new tile
	put_image(game, game->textures.idle_player, (y_pos * SIZE), 
		   new_pos * (SIZE + ((SIZE / 3) * 1)));
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	//1/3 missing in new tile
	put_image(game, game->textures.idle_player, (y_pos * SIZE), 
		   new_pos * (SIZE + ((SIZE / 3) * 2)));
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));
	
	//new tile
	put_image(game, game->textures.idle_player, (y_pos * SIZE), 
		   new_pos * SIZE);
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	game->player.x = new_pos;
	//falta checkar se ganhei o jogo
}

void	move_left(t_game *game)
{
	int		previous_pos;
	int		new_pos;
	int		y_pos;
	void	*old_floor;

	previous_pos = game->player.x;
	new_pos = game->player.x - 1;
	y_pos = game->player.y;
	old_floor = game->textures.floor;

	//restore correct floor at old position
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	//2/3 missing in new tile
	put_image(game, game->textures.idle_player, (y_pos * SIZE), 
		   new_pos * (SIZE - ((SIZE / 3) * 1)));
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	//1/3 missing in new tile
	put_image(game, game->textures.idle_player, (y_pos * SIZE), 
		   new_pos * (SIZE - ((SIZE / 3) * 2)));
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));
	
	//new tile
	put_image(game, game->textures.idle_player, (y_pos * SIZE), 
		   new_pos * SIZE);
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	game->player.x = new_pos;
	//falta checkar se ganhei o jogo
}
