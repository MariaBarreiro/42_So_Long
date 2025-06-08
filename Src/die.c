/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:48:20 by mda-enca          #+#    #+#             */
/*   Updated: 2025/06/06 10:14:34 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

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
	exit (1);
}

void	free_everything(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->map != NULL)
		free_map(game->map, game);
	free(game);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == NULL)
		free(map);
	while (i < (game->height ))
	{
		free(map[i]);
		i++;
	}
	free(map);
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
