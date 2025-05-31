/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:55:31 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/31 10:40:49 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	validate_map(t_game *game)
{
	
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	*game;

	if (ac == 2)
	{
		//isnt it a redundancy? opening here and then opening again when i load the map?
		// //open the map i'm passing in the av[1]
		// fd = open(av[1], O_RDONLY);
		// //check for error
		// if (fd < 0)
		// {
		// 	//error opening the map
		// 	return (0); //for now!!
		// }

		//read/load map
		load_map(av[1], game);
	}
	return (0);
}
