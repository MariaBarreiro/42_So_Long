#include "so_long.h"

void	load_map(char *map_file, y_game *game)
{

}

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
