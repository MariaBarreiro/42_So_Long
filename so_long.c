#include <fcntl.h> //read library
#include <unistd.h> //close, read, write library
#include <stdlib.h> //malloc, free, exit library
#include <stdio.h> //perror library
#include <string.h> //strerror library
#include <gnl/get_next_line.h> //include gnl

char **read_map(int fd)
{
	
}

int	main(int ac, char **av)
{
	int fd;
	char **map;

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
		map = read_map(fd);
	}
	return (0);
}
