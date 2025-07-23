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

void	check_win(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->c_gathered++;
		game->map[game->player.y][game->player.x] = '0';
	}
	if (game->map[game->player.y][game->player.x] == 'E' 
			&& game->c_gathered != game->collectibles)
		return ;
	if (game->map[game->player.y][game->player.x] == 'E'
			&& game->c_gathered == game->collectibles)
	{
		ft_printf("You win!\n");
		ft_exit(game);
	}
}

void	move_up(t_game *game)
{
	int		previous_pos;
	int		new_pos;
	int		x_pos;
	void	*old_floor;

	previous_pos = game->player.y;
	new_pos = game->player.y - 1;
	x_pos = game->player.x;
	old_floor = "../../Textures/tile/floor.xpm";

	//restore correct floor at old position
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	//2/3 missing in new tile
	put_image(game, "../../Textures/player/player.xpm", (x_pos * SIZE), 
		   new_pos * (SIZE - ((SIZE / 3) * 1)));
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	//1/3 missing in new tile
	put_image(game, "../../Textures/player/player.xpm", (x_pos * SIZE), 
		   new_pos * (SIZE - ((SIZE / 3) * 2)));
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));
	
	//new tile
	put_image(game, "../../Textures/player/player.xpm", (x_pos * SIZE), 
		   new_pos * SIZE);
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	game->player.y = new_pos;
	check_win(game);
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
	old_floor = "../../Textures/tile/floor.xpm";

	//restore correct floor at old position
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	//2/3 missing in new tile
	put_image(game, "../../Textures/player/player.xpm", (x_pos * SIZE), 
		   new_pos * (SIZE + ((SIZE / 3) * 1)));
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	//1/3 missing in new tile
	put_image(game, "../../Textures/player/player.xpm", (x_pos * SIZE), 
		   new_pos * (SIZE + ((SIZE / 3) * 2)));
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));
	
	//new tile
	put_image(game, "../../Textures/player/player.xpm", (x_pos * SIZE), 
		   new_pos * SIZE);
	put_image(game, old_floor, (x_pos * SIZE), (previous_pos * SIZE));

	game->player.y = new_pos;
	check_win(game);
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
	old_floor = "../../Textures/tile/floor.xpm";

	//restore correct floor at old position
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	//2/3 missing in new tile
	put_image(game, "../../Textures/player/player.xpm", (y_pos * SIZE), 
		   new_pos * (SIZE + ((SIZE / 3) * 1)));
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	//1/3 missing in new tile
	put_image(game, "../../Textures/player/player.xpm", (y_pos * SIZE), 
		   new_pos * (SIZE + ((SIZE / 3) * 2)));
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));
	
	//new tile
	put_image(game, "../../Textures/player/player.xpm", (y_pos * SIZE), 
		   new_pos * SIZE);
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	game->player.x = new_pos;
	check_win(game);
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
	old_floor = "../../Textures/tile/floor.xpm";

	//restore correct floor at old position
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	//2/3 missing in new tile
	put_image(game, "../../Textures/player/player.xpm", (y_pos * SIZE), 
		   new_pos * (SIZE - ((SIZE / 3) * 1)));
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	//1/3 missing in new tile
	put_image(game, "../../Textures/player/player.xpm", (y_pos * SIZE), 
		   new_pos * (SIZE - ((SIZE / 3) * 2)));
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));
	
	//new tile
	put_image(game, "../../Textures/player/player.xpm", (y_pos * SIZE), 
		   new_pos * SIZE);
	put_image(game, old_floor, (y_pos * SIZE), (previous_pos * SIZE));

	game->player.x = new_pos;
	check_win(game);
}
