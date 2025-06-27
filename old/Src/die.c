/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:48:20 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/15 16:11:18 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"
#include <stdlib.h>

void	die(int num, t_game *game)
{
	ft_printf("Error\n");
	if (num == 1)
		ft_printf("Generic map error!\n");
	else if (num == 2)
		ft_printf("Map must have a \".ber\" extension!\n");
	else if (num == 3)
		ft_printf("File doesn't exist or is not reachable!\n");
	else if (num == 4)
		ft_printf("Map is the wrong size!\n");
	else if (num == 5)
		ft_printf("Wrong map format!\n");
	else if (num == 6)
		ft_printf("Malloc didn't work out!\n");
	else if (num == 7)
		ft_printf("The elements are wrong!\n");
	else if (num == 8)
		ft_printf("Mlx error!\n");
	else if (num == 9)
		ft_printf("Not a valid_path!\n");
	if (num != 2 && num != 1)
		free_everything(game);
	exit (EXIT_SUCCESS);
}

void	free_everything(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->map != NULL)
		free_map(game->map, game);
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		// destroy_textures(game);
	}
	if (game->mlx_win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == NULL)
		return (free(game->map));
	while (i < (game->height))
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_array(char **map, int lines)
{
	int	i;

	i = 0;
	if (map[0] == NULL)
	{
		free(map);
		return ;
	}
	while (i < lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	 ft_exit(t_game *game)
{
	free_everything(game);
	exit (EXIT_SUCCESS);
}
