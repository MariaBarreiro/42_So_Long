/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:49:58 by mda-enca          #+#    #+#             */
/*   Updated: 2025/07/12 16:05:18 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

///Includes///
# include <fcntl.h>									//read library
# include <unistd.h>								//close, read, write library
# include <stdlib.h>								//malloc, free, exit library
# include <stdio.h>									//perror library
# include <string.h>								//strerror library
# include <X11/keysym.h>
# include <X11/X.h>
# include "../Libs/42_Libft/42_Gnl/get_next_line.h"			//include gnl
# include "../Libs/42_Libft/Inc/libft.h"					//include libft
# include "../Libs/minilibx-linux/mlx.h"					//include mlx
# include "../Libs/42_Libft/42_Ft_Printf/Inc/ft_printf.h"	//include printf

//Defines

# define SIZE 64

///Structs///

//coordinates
//good to keep track of where the player currently is
//also good to know where the door is
typedef struct s_point_in_map
{
	int	x;
	int	y;
}	t_point_in_map;

//MLX image structure
//Needed to manipulate pixels

typedef struct s_image
{
	void	*mlx_img;				//pointer to the MLX image
	void	*addr;					//raw pixel data pointer
	int		bpp;					//bits per pixel
	int		line_len;				//byter per row
	int		endian;					//byte order
}	t_image;

//loaded textures

typedef struct s_textures
{
	void	*floor;

	void	*wall;

	void	*idle_player;

	void	*exit_active;
	void	*exit_inactive;

	void	*collectible;
}	t_textures;

//main game structure
typedef struct	s_game
{
	char			**map;			//2d map matrix
	int				width;			//number of columns
	int				height;			//number of rows
	int				collectibles;	//number of collectibles
	int				c_gathered;		//number of collectibles gathered
	int				e_reached;		//bollean of exit reached or not
	int				moves;			//number of moves done
	t_point_in_map	coords;			//coordinates
	t_point_in_map	player;			//coordinates of player
	t_point_in_map	exit;			//coordinates of exit
	t_point_in_map	tiles;			//coordinates of the tiles
	void			*mlx_ptr;		//MLX pointer
	void			*mlx_win_ptr;	//MLX Window pointer
	t_image			img;			//image struct
	t_textures		textures;		//textures struct
}	t_game;

///Functions///
///General///

t_game	*init(void);
void	init_game(t_game *game);
void	init_mlx(t_game *game);
void	die(int num, t_game *game);
void	free_everything(t_game *game);
void	free_map(char **map, t_game *game);
void	free_array(char **map, int lines);

///Maps///

void	check_extension(char *file);
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
void	final_check(t_game *game);

//Render//

void	render_map(t_game *game);
void	put_walls(t_game *game, int x, int y);
void	put_floor(t_game *game, int x, int y);
void	put_rest(t_game *game, int x, int y);
void	put_image(t_game *game, void *img, int tile_x, int tile_y);
void	load_textures(t_game *game);
void	*select_exit(t_game *game);
void	render_window(t_game *game);
void	render(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	render_corners(t_game *game, int x, int y);
void	render_borders(t_game *game, int x, int y);

//Destroy and exit//

void	destroy_textures(t_game *game);
int		ft_exit(t_game *game);

//Movement//

void	check_win(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
int		handle_keypress(int keysym, t_game *game);
void	validate_move_up(t_game *game);
void	validate_move_left(t_game *game);
void	validate_move_down(t_game *game);
void	validate_move_right(t_game *game);

#endif
