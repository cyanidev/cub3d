/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_between_lines.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:44 by Andie             #+#    #+#             */
/*   Updated: 2025/05/20 19:33:00 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "helper.h"

float	point_to_angle(t_point pos, t_point pt)
{
	t_point	delta;
	float	angle;

	delta.px = pt.px - pos.px;
	delta.py = pt.py - pos.py;
	angle = (atan2(delta.py, delta.px));
	angle = angle * (180.0 / PI);
	return (angle);
}

int	norm(float angle)
{
	return ((int)angle % 360);
}

float	det(t_point a, t_point b)
{
	return (a.px * b.py - a.py * b.px);
}

t_point	get_intersection_between_lines(t_line line1, t_line line2, int *error)
{
	t_point		xdiff;
	t_point		ydiff;
	t_point		d;
	t_intersec	inter;

	xdiff = point(line1.a.px - line1.b.px, line2.a.px - line2.b.px);
	ydiff = point(line1.a.py - line1.b.py, line2.a.py - line2.b.py);
	inter.div = det(xdiff, ydiff);
	if (inter.div < EPS || inter.div == 0)
	{
		*error = 1;
		return (point(0, 0));
	}
	d = point(det(line1.a, line1.b), det(line2.a, line2.b));
	inter.x = det(d, xdiff) / inter.div;
	inter.y = det(d, ydiff) / inter.div;
	return (point(inter.x, inter.y));
}
