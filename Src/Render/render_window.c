/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:39:49 by mda-enca          #+#    #+#             */
/*   Updated: 2025/07/23 09:40:01 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"
#include <X11/X.h>

void	render_window(t_game *game)
{
	if (game->mlx_ptr == NULL)
		die(8, game);
	game->mlx_win_ptr = mlx_new_window(game->mlx_ptr, (game->width * SIZE),
			(game->height * SIZE), "so_long");
	if (game->mlx_win_ptr == NULL)
	{
		free (game->mlx_win_ptr);
		die(8, game);
	}
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, (game->width * SIZE),
			(game->height * SIZE));
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
}

void	render(t_game *game)
{
	render_window(game);
	if (!game->mlx_win_ptr)
		die(8, game);
	game->c_gathered = 0;
	render_map(game);
	mlx_hook(game->mlx_win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->mlx_win_ptr, DestroyNotify, StructureNotifyMask, &ft_exit,
		game);
	mlx_loop(game->mlx_ptr);
}
