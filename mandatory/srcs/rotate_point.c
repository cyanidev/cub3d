/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:43:33 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 22:09:15 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "cub_ray.h"

float	fix_angle(float angle)
{
	if (angle < 0)
		angle += 360.0;
	if (angle > 359.0)
		angle -= 360.0;
	return (angle);
}

float	deg2_rad(float angle)
{
	return (fix_angle(angle) * PI / 180.0);
}

t_point	rotate_point(t_point pt, float angle)
{
	float	x;
	float	y;

	x = pt.px;
	y = pt.py;
	pt.px = x * cos(deg2_rad(angle)) - y * sin(deg2_rad(angle));
	pt.py = x * sin(deg2_rad(angle)) + y * cos(deg2_rad(angle));
	return (pt);
}

t_line	rotate_line(t_line line, float angle)
{
	line.a = rotate_point(line.a, angle);
	line.b = rotate_point(line.b, angle);
	return (line);
}
