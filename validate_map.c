/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:35:19 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/31 15:15:24 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validation(t_game *game)
{
	check_map_size(game);	
}

void	check_map_size(t_game *game)
{
	int	i;

	i = 0;
	//minimum size check
	if (game->height < 3 || game->width < 3 || (game->height + game->width) <= 7)
	{
		printf("Minimum size not met! Error needs handling! (check_map_size)");
	}
	//because its an array and it starts at 0, I need to take one value of Height!!!!!!!
	while (i < (game->height - 1))
	{
		//rectangle check
		if (modified_strlen(game->map[i]) != game->width && game->map[i] != NULL)
		{
			printf("map not a rectangle!!Error needs handling!! (check map size)");
		}
		i++;
	}
}
