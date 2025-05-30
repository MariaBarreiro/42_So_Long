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
#include "Gnl/get_next_line.h" //include gnl

///Structs///

//main game structure
typedef struct  s_game
{
	char	**map;					//2d map matrix
	int		width;					//number of columns
	int		height;					//number of rows
}t_game;

#endif
