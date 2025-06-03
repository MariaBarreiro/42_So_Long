/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:38:27 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/30 18:23:15 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

///Includes///

#include <fcntl.h> //read library
#include <unistd.h> //close, read, write library
#include <stdlib.h> //malloc, free, exit library
#include <stdio.h> //perror library
#include <string.h> //strerror library
#include "Libft-Gnl/42_Gnl/get_next_line.h" //include gnl
#include "Libft-Gnl/42_Libft/libft.h" //include libft

///Structs///

//coordinates
//good to keep track of where the player currently is
//also good to know where the door is
typedef struct s_point_in_map
{
	int x;
	int	y;
}t_point_in_map;

//main game structure

typedef struct  s_game
{
	char			**map;			//2d map matrix
	int				width;			//number of columns
	int				height;			//number of rows
	int				collectibles;	//number of collectibles
	int				c_gathered;		//number of collectibles gathered
	int				e_reached;	//bollean to keep track if the exit was reached or not
	t_point_in_map	coords;			//coordinates
	t_point_in_map	player;			//coordinates of player
	t_point_in_map	exit;			//coordinates of exit
}t_game;


///Functions///

///Map stuff///
void	load_map(char *map_file, t_game *game);
int		count_lines(char *map_file);
void	fill_map(int fd, t_game *game);
int		modified_strlen(char *map);
void	map_validation(t_game *game);
void	check_map_size(t_game *game);
void	check_borders(t_game *game);
void	check_map_assets(t_game *game);
void	count_assets(t_game *game);
void	check_map_content(t_game *game);
void	check_valid_path(t_game *game);
void	flood_fill(char **map, t_game *game, int x, int y);

#endif
