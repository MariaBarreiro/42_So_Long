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
		ft_printf("Generic map error! No map given or too many args!\n");
	else if (num	== 2)
		ft_printf("Map must have a \".ber\" extension!\n");
	else if (num == 3)
		ft_printf("File doesn't exist or is not reachable!\n");
	else if (num == 4)
		ft_printf("Map is not a rectangle!\n");
	else if (num == 5)
		ft_printf("Map must be fully enclosed by walls!\n");
	else if (num == 6)
		ft_printf("Unknown symbols!\n");
	else if (num == 7)
		ft_printf("Malloc didn't work out!\n");
	if (num != 2 && num != 1)
		free(game);

}
