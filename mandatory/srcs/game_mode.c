/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:16 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 21:28:28 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

//cub->player->camera->pos;
int	game_mode(t_cub *cub)
{
	t_map_editor	minimap;

	if (cub->game_mode != GAME)
		clean_pixels(cub->game_img);
	cub->game_mode = GAME;
	minimap = map_editor();
	minimap.screen_zoom = 10;
	minimap.screen_center = point(
			cub->player->camera->pos.px * minimap.screen_zoom,
			cub->player->camera->pos.py * minimap.screen_zoom);
	clean_pixels(cub->minimap_img);
	ray_casting(cub, minimap);
	render_normal_mode(cub);
}
