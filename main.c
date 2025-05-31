/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:36:08 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/31 17:20:48 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_game	*game;

	if (ac == 2)
	{
		//open the map i'm passing in the av[1]
		fd = open(av[1], O_RDONLY);
		//check for error
		if (fd < 0)
		{
			//error opening the map
			return (0); //for now!!
		}

		//read/load map
		load_map(av[1], game);
		//validates the map
		map_validation(game);
	}
	return (0);
}
