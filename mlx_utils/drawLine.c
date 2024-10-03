/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putPixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:56:01 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/09 18:55:05 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

float	ft_distance_2_points(t_point a, t_point b)
{
	float	x;
	float	y;

	x = pow((b.px - a.px), 2);
	y = pow((b.py - a.py), 2);
	return (sqrt(x + y));
}

t_color	color_degradade(t_point init, t_point end, t_point current)
{
	float	total_distance;
	float	actual_distance;
	float	result;

	total_distance = ft_distance_2_points(init, end);
	actual_distance = ft_distance_2_points(init, current);
	result = actual_distance / total_distance;
	return (color_mix(init.color, end.color, result));
}

static void	ft_clone(t_point *point, t_line line, int x, int y)
{
	point->px = x;
	point->py = y;
	(void)line;
	point->color = color_degradade(line.a, line.b, *point);
}

static void	bb_init(t_bb *bb, t_point f, t_point s)
{
	bb->x0 = f.px;
	bb->y0 = f.py;
	bb->x1 = s.px;
	bb->y1 = s.py;
	bb->dx = ft_abs(bb->x1 - bb->x0);
	bb->dy = ft_abs(bb->y1 - bb->y0);
	if (bb->x0 < bb->x1)
		bb->sx = 1;
	else
		bb->sx = -1;
	if (bb->y0 < bb->y1)
		bb->sy = 1;
	else
		bb->sy = -1;
	bb->err = bb->dx - bb->dy;
	bb->line.a = f;
	bb->line.b = s;
}

void	ft_draw_pixel(t_point pt, t_img *img)
{
	put_pixel(img, pt);
}

void	draw_line(t_point f, t_point s, t_img *map_display)
{
	t_bb		bb;
	t_point		tmp;
	int			e2;

	bb_init(&bb, f, s);
	while (1)
	{
		ft_clone(&tmp, bb.line, bb.x0, bb.y0);
		ft_draw_pixel(tmp, map_display);
		if (bb.x0 == bb.x1 && bb.y0 == bb.y1)
			break ;
		e2 = 2 * bb.err;
		if (e2 > -bb.dy)
		{
			bb.err -= bb.dy;
			bb.x0 += bb.sx;
		}
		if (e2 < bb.dx)
		{
			bb.err += bb.dx;
			bb.y0 += bb.sy;
		}
	}
}
