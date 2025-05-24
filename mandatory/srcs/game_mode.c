/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:16 by Andie             #+#    #+#             */
/*   Updated: 2025/05/24 13:08:56 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

//cub->player->camera->pos;
/*int	game_mode(t_cub *cub)
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
}*/

int	game_mode(t_cub *cub)
{

	t_map_editor	minimap;

	if (cub->game_mode != GAME)
		clean_pixels(cub->game_img);

	cub->game_mode = GAME;
	minimap = map_editor();
	minimap.screen_zoom = 10;
	minimap.screen_center = point(cub->player->camera->pos.px * minimap.screen_zoom,
	cub->player->camera->pos.py * minimap.screen_zoom);//cub->player->camera->pos;
	
	clean_pixels(cub->minimap_img);

	draw_grid(minimap, cub->minimap_img, color_from_rgb(100, 100, 100));
	draw_map_walls(cub, minimap, cub->minimap_img);
	draw_player(cub, minimap, color_from_rgb(255, 255, 0), cub->minimap_img);


	ray_casting(cub, minimap);


	render_bonus_mode(cub);

	//render_normal_mode(cub);

}
