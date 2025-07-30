/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:47:38 by mda-enca          #+#    #+#             */
/*   Updated: 2025/07/12 15:49:17 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_game	*game;

	if (ac == 2)
	{
		check_extension(av[1]);
		game = init();
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			die(1, game);
		load_map(av[1], game);
		map_validation(game);
		render(game);
		ft_exit(game);
	}
	return (0);
}

void	check_extension(char *file)
{
	char	*ber_extension;
	char	*extension;

	ber_extension = ".ber";
	extension = file + (ft_strlen(file) - 4);
	if (ft_strncmp(extension, ber_extension, 4) != 0)
		die(2, NULL);
}

void	map_validation(t_game *game)
{
	check_map_size(game);
	check_borders(game);
	check_map_assets(game);
	count_assets(game);
	check_map_content(game);
	check_valid_path(game);
	final_check(game);
}
