/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:43:41 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/11 13:44:01 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	*select_grass(t_game *game, int x, int y)
{
	void	*texture;
	
	texture = select_grass_combinations(game, x, y);
	if (texture != NULL)
		return (texture);
	return (select_grass_rest(game, x, y));
}

void	*select_grass_combinations(t_game *game, int x, int y)
{
	char	**map;
	int		up;
	int		down;
	int		left;
	int		right;

	map = game->map;
	up = y > 0 && map[y - 1][x] == '1';
	down = y < (game->height - 1) && map[y + 1][x] == 1;
	left = x > 0 && map[x - 1][y] == '1';
	right = x < (game->width - 1) && map[y][x + 1] == 1;
	if (up == 1 && left == 1 && down == 0 && right == 0)
		return (game->textures.grass_b_lft_up);
	else if (down == 1 && left == 1 && right == 0 && up == 0)
		return (game->textures.grass_b_lft_dwn);
	else if (right == 1 && up == 1 && left == 0 && down == 0)
		return (game->textures.grass_b_rght_up);
	else if (right == 1 && down == 1 && up == 0 && left == 0)
		return (game->textures.grass_b_rght_dwn);
	return (NULL);
}

void	*select_grass_rest(t_game *game, int x, int y)
{
	char	**map;
	int		up;
	int		down;
	int		left;
	int		right;

	map = game->map;
	up = y > 0 && map[y - 1][x] == '1';
	down = y < (game->height - 1) && map[y + 1][x] == 1;
	left = x > 0 && map[x - 1][y] == '1';
	right = x < (game->width - 1) && map[y][x + 1] == 1;
	if (up == 0 && left == 0 && down == 0 && right == 0)
		return (game->textures.grass);
	else if (up == 1 && down == 0 && left == 0 && right == 0)
		return (game->textures.grass_b_up);
	else if (down == 1 && up == 0 && left == 0 && right == 0)
		return (game->textures.grass_b_dwn);
	else if (right == 1 && up == 0 && left == 0 && down == 0)
		return (game->textures.grass_b_rght);
	else if (left == 1 && up == 0 && down == 0 && right == 0)
		return (game->textures.grass_b_lft);
	else if (up == 1 && left == 1 && down == 1 && right == 1)
		return (game->textures.surrounded_by_water);
	return (NULL);
}

void	*select_water(t_game *game, int x, int y)
{

	char	**map;
	int		up;
	int		down;
	int		left;
	int		right;

	map = game->map;
	up = y > 0 && map[y - 1][x] != '1';
	down = y < (game->height - 1) && map[y + 1][x] != 1;
	left = x > 0 && map[x - 1][y] != '1';
	right = x < (game->width - 1) && map[y][x + 1] != 1;
	if (left == 1 && right == 0 && down == 0 && up == 0)
		return (game->textures.water_b_lft);
	else if (left == 0 && right == 1 && down == 0 && up == 0)
		return (game->textures.water_b_rght);
	else if (left == 0 && right == 0 && down == 1 && up == 1)
		return (game->textures.water_from_lft_rght);
	else if (left == 1 && right == 1 && down == 0 && up == 0)
		return (game->textures.water_from_up_dwn);
	return (NULL);
}
