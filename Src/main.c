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
	t_game	game;

	if (ac == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		check_extension(av[1]);
		init(&game);
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			die(1, &game);
		load_map(av[1], &game);
		map_validation(&game);
		render(&game);
		ft_exit(&game);
	}
	return (0);
}

void	check_extension(char *file)
{
	char	*ber_extension;
	char	*extension;
	char	*no_path;

	ber_extension = ".ber";
	extension = file + (ft_strlen(file) - 4);
	no_path = remove_path(file);
	if (ft_strncmp(extension, ber_extension, 4) != 0)
		die(2, NULL);
	if (ft_strcmp(no_path, ".ber") == 0)
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*remove_path(char *file)
{
	int		i;

	i = 0;
	while (file[i])
		i++;
	i -= 1;
	while (file[i] != '/')
		i--;
	i += 1;
	return (file + i);
}
