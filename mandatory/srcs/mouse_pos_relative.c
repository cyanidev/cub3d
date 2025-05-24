/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pos_relative.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:08 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 22:00:30 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

t_point	mouse_pos_relative(t_cub *cub, t_win *win)
{
	t_point	result;
	int		x;
	int		y;

	x = 0;
	y = 0;
	result = cub->map_editor.screen_center;
	mlx_mouse_get_pos(cub->mlx, win->mlx_win, &x, &y);
	result.px = cub->last_mouse_grab.px - x;
	result.py = cub->last_mouse_grab.py - y;
	result.px = result.px * 100.0f / (float)
		(200.0f - cub->map_editor.screen_zoom);
	result.py = result.py * 100.0f / (float)
		(200.0f - cub->map_editor.screen_zoom);
	result.px += cub->map_editor.screen_center.px;
	result.py += cub->map_editor.screen_center.py;
	cub->last_mouse_grab = point(x, y);
	return (result);
}
