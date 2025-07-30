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
	if (game->map[game->player.y - 1][game->player.x] == '1')
	{
		game->moves -= 1;
		return ;
	}
	if (game->map[game->player.y - 1][game->player.x] == 'C')
		game->c_gathered += 1;
	if (game->map[game->player.y - 1][game->player.x] == 'E')
	{
		if (game->c_gathered == game->collectibles)
		{
			game->player.y = game->player.y - 1;
			game->e_reached = 1;
			check_win(game);
		}
		else
		{
			game->moves -= 1;
			return ;
		}
	}
	game->map[game->player.y][game->player.x] = '0';
	game->map[game->player.y - 1][game->player.x] = 'P';
	game->player.y = game->player.y - 1;
	render_map(game);
}

void	move_down(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] == '1')
	{
		game->moves -= 1;
		return ;
	}
	if (game->map[game->player.y + 1][game->player.x] == 'C')
		game->c_gathered += 1;
	if (game->map[game->player.y + 1][game->player.x] == 'E')
	{
		if (game->c_gathered == game->collectibles)
		{
			game->player.y = game->player.y + 1;
			game->e_reached = 1;
			check_win(game);
		}
		else
		{
			game->moves -= 1;
			return ;
		}
	}
	game->map[game->player.y][game->player.x] = '0';
	game->map[game->player.y + 1][game->player.x] = 'P';
	game->player.y = game->player.y + 1;
	render_map(game);
}

void	move_right(t_game *game)
{
	if (game->map[game->player.y][game->player.x + 1] == '1')
	{
		game->moves -= 1;
		return ;
	}
	if (game->map[game->player.y][game->player.x + 1] == 'C')
		game->c_gathered += 1;
	if (game->map[game->player.y][game->player.x + 1] == 'E')
	{
		if (game->c_gathered == game->collectibles)
		{
			game->player.x = game->player.x + 1;
			game->e_reached = 1;
			check_win(game);
		}
		else
		{
			game->moves -= 1;
			return ;
		}
	}
	game->map[game->player.y][game->player.x] = '0';
	game->map[game->player.y][game->player.x + 1] = 'P';
	game->player.x = game->player.x + 1;
	render_map(game);
}

void	move_left(t_game *game)
{
	if (game->map[game->player.y][game->player.x - 1] == '1')
	{
		game->moves -= 1;
		return ;
	}
	if (game->map[game->player.y][game->player.x - 1] == 'C')
		game->c_gathered += 1;
	if (game->map[game->player.y][game->player.x - 1] == 'E')
	{
		if (game->c_gathered == game->collectibles)
		{
			game->player.x = game->player.x - 1;
			game->e_reached = 1;
			check_win(game);
		}
		else
		{
			game->moves -= 1;
			return ;
		}
	}
	game->map[game->player.y][game->player.x] = '0';
	game->map[game->player.y][game->player.x - 1] = 'P';
	game->player.x = game->player.x - 1;
	render_map(game);
}
