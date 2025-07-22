/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:27:51 by mda-enca          #+#    #+#             */
/*   Updated: 2025/07/12 16:31:27 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"


void	*select_exit(t_game *game)
{
	if (game->c_gathered == game->collectibles && game->e_reached == 1)
		return (game->textures.exit_active);
	return (game->textures.exit_inactive);
}
