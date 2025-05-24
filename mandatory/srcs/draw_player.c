/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:40:06 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 19:47:50 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

int	draw_player(t_cub *cub, t_map_editor map_editor, t_color col, t_img *img)
{
	t_point	pos;
	t_point	fov1;
	t_point	fov2;

	pos = cub->player->camera->pos;
	fov1 = point(pos.px + (cub->max_dist * 5 * cub->fov1_deltas.px),
			pos.py + (cub->max_dist * 5 * cub->fov1_deltas.py));
	fov2 = point(pos.px + (cub->max_dist * 5 * cub->fov2_deltas.px),
			pos.py + (cub->max_dist * 5 * cub->fov2_deltas.py));
	pos = remap_point(pos, map_editor.screen_zoom, map_editor.screen_center,
			img->resolution);
	fov1 = remap_point(fov1, map_editor.screen_zoom,
			map_editor.screen_center, img->resolution);
	fov2 = remap_point(fov2, map_editor.screen_zoom,
			map_editor.screen_center, img->resolution);
	pos.px = (int)pos.px;
	pos.py = (int)pos.py;
	draw_circle(5, img, color_point(pos, col));
	pos.color = col;
	fov1.color = col;
	fov2.color = col;
	draw_line(pos, fov1, img);
	draw_line(pos, fov2, img);
	return (1);
}
