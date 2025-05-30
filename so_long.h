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

///Structs///

//main game structure
typedef struct  s_game
{
	char	**map;					//2d map matrix
	int		width;					//number of columns
	int		height;					//number of rows
}t_game;

#endif
