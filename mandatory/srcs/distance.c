/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:39:28 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 19:47:01 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "engine.h"
#include "engine_obj.h"
#include <time.h>

float	distance_between_points(t_point a, t_point b)
{
	float	result;

	result = sqrt(((b.px - a.px) * (b.px - a.px))
			+ ((b.py - a.py) * (b.py - a.py)));
	return (result);
}

int	draw_line_remap(t_line line, t_map_editor map_edtr, t_img *img, t_color col)
{
	t_point	a;
	t_point	b;

	a = remap_point(line.a, map_edtr.screen_zoom,
			map_edtr.screen_center, img->resolution);
	b = remap_point(line.b, map_edtr.screen_zoom,
			map_edtr.screen_center, img->resolution);
	a.color = col;
	b.color = col;
	draw_line(a, b, img);
	return (1);
}

float	get_min_dist(t_line line, t_point p)
{
	float	dist1;
	float	dist2;

	dist1 = distance_between_points(line.a, p);
	dist2 = distance_between_points(line.b, p);
	if (dist2 < dist1)
		return (dist2);
	return (dist1);
}
