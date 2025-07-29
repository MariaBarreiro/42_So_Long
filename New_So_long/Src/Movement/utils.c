/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:42:20 by mda-enca          #+#    #+#             */
/*   Updated: 2025/07/12 16:45:07 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_exit(game);
	if (keysym == XK_w || keysym == XK_Up)
		validate_move_up(game);
	if (keysym == XK_s || keysym == XK_Down)
		validate_move_down(game);
	if (keysym == XK_a || keysym == XK_Left)
		validate_move_left(game);
	if (keysym == XK_d || keysym == XK_Right)
		validate_move_right(game);
	return (0);
}

void	validate_move_up(t_game *game)
{
	t_point_in_map	player_pos;

	player_pos = game->player;
	if ((game->map[player_pos.y - 1][player_pos.x] == 'E'
		&& game->e_reached == 0
		&& game->c_gathered != game->collectibles)
		|| game->map[player_pos.y - 1][player_pos.x] == 1)
		return ;
	else
	{
		move_up(game);
		game->moves += 1;
	}
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("Total collectibles: %d\n", game->collectibles);
	ft_printf("Collectibles gathered: %d\n", game->c_gathered);
}

void	validate_move_left(t_game *game)
{
	t_point_in_map	player_pos;

	player_pos = game->player;
	if ((game->map[player_pos.y][player_pos.x - 1] == 'E'
		&& game->e_reached == 0
		&& game->c_gathered != game->collectibles)
		|| game->map[player_pos.y][player_pos.x - 1] == 1)
		return ;
	else
	{
		move_left(game);
		game->moves += 1;
	}
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("Total collectibles: %d\n", game->collectibles);
	ft_printf("Collectibles gathered: %d\n", game->c_gathered);
}

void	validate_move_down(t_game *game)
{
	t_point_in_map	player_pos;

	player_pos = game->player;
	if ((game->map[player_pos.y + 1][player_pos.x] == 'E'
		&& game->e_reached == 0
		&& game->c_gathered != game->collectibles)
		|| game->map[player_pos.y + 1][player_pos.x] == 1)
		return ;
	else
	{
		move_down(game);
		game->moves += 1;
	}
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("Total collectibles: %d\n", game->collectibles);
	ft_printf("Collectibles gathered: %d\n", game->c_gathered);
}

void	validate_move_right(t_game *game)
{
	t_point_in_map	player_pos;

	player_pos = game->player;
	if ((game->map[player_pos.y][player_pos.x + 1] == 'E'
		&& game->e_reached == 0
		&& game->c_gathered != game->collectibles)
		|| game->map[player_pos.y][player_pos.x + 1] == 1)
		return ;
	else
	{
		move_right(game);
		game->moves += 1;
	}
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("Total collectibles: %d\n", game->collectibles);
	ft_printf("Collectibles gathered: %d\n", game->c_gathered);
}
