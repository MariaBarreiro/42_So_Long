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
			&& game->c_gathered == game->collectibles
			&& game->e_reached == 1)
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

	previous_pos = game->player.y;
	new_pos = game->player.y - 1;
	x_pos = game->player.x;

	if (game->map[new_pos][x_pos] == '1')
	{
		game->moves -= 1;
		return ;
	}
	if (game->map[new_pos][x_pos] == 'C')
		game->c_gathered += 1;
	if (game->map[new_pos][x_pos] == 'E')
	{
		if (game->c_gathered == game->collectibles)
		{
			game->player.y = new_pos;
			game->e_reached = 1;
			check_win(game);
		}
		else
		{
			game->moves -= 1;
			return ;
		}
	}
	game->map[previous_pos][x_pos] = '0';
	game->map[new_pos][x_pos] = 'P';
	game->player.y = new_pos;

	render_map(game);
}

void	move_down(t_game *game)
{
	int		previous_pos;
	int		new_pos;
	int		x_pos;

	previous_pos = game->player.y;
	new_pos = game->player.y + 1;
	x_pos = game->player.x;
	
	if (game->map[new_pos][x_pos] == '1')
	{
		game->moves -= 1;
		return ;
	}
	if (game->map[new_pos][x_pos] == 'C')
		game->c_gathered += 1;
	if (game->map[new_pos][x_pos] == 'E')
	{
		if (game->c_gathered == game->collectibles)
		{
			game->player.y = new_pos;
			game->e_reached = 1;
			check_win(game);
		}
		else
		{
			game->moves -= 1;
			return ;
		}
	}
	game->map[previous_pos][x_pos] = '0';
	game->map[new_pos][x_pos] = 'P';
	game->player.y = new_pos;

	render_map(game);
}

void	move_right(t_game *game)
{
	int		previous_pos;
	int		new_pos;
	int		y_pos;

	previous_pos = game->player.x;
	new_pos = game->player.x + 1;
	y_pos = game->player.y;

	if (game->map[y_pos][new_pos] == '1')
	{
		game->moves -= 1;
		return ;
	}
	if (game->map[y_pos][new_pos] == 'C')
		game->c_gathered += 1;
	if (game->map[y_pos][new_pos] == 'E')
	{
		if (game->c_gathered == game->collectibles)
		{
			game->player.x = new_pos;
			game->e_reached = 1;
			check_win(game);
		}
		else
		{
			game->moves -= 1;
			return ;
		}
	}
	game->map[y_pos][previous_pos] = '0';
	game->map[y_pos][new_pos] = 'P';
	game->player.x = new_pos;

	render_map(game);
}

void	move_left(t_game *game)
{
	int		previous_pos;
	int		new_pos;
	int		y_pos;

	previous_pos = game->player.x;
	new_pos = game->player.x - 1;
	y_pos = game->player.y;

	if (game->map[y_pos][new_pos] == '1')
	{
		game->moves -= 1;
		return ;
	}
	if (game->map[y_pos][new_pos] == 'C')
		game->c_gathered += 1;
	if (game->map[y_pos][new_pos] == 'E')
	{
		if (game->c_gathered == game->collectibles)
		{
			game->player.x = new_pos;
			game->e_reached = 1;
			check_win(game);
		}
		else
		{
			game->moves -= 1;
			return ;
		}
	}
	game->map[y_pos][previous_pos] = '0';
	game->map[y_pos][new_pos] = 'P';
	game->player.x = new_pos;

	render_map(game);
}
