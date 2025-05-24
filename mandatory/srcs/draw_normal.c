/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:40:00 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:40:00 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

t_point	ft_normalize(t_point point)
{
	t_point	result;
	double	xd;
	float	inv_sqr;

	result = point;
	xd = (point.px * point.px) + (point.py * point.py) + (point.pz * point.pz);
	inv_sqr = 0;
	if (xd)
	{
		inv_sqr = sqrt(xd);
		inv_sqr = 1 / inv_sqr;
	}
	result.px = point.px * inv_sqr;
	result.py = point.py * inv_sqr;
	result.pz = point.pz * inv_sqr;
	return (result);
}

void	draw_normal(t_line line, t_img *img)
{
	t_point	p10;
	t_point	p0;
	t_point	p1;
	t_point	normal;

	p1 = line.a;
	p0 = line.a;
	p10 = line.a;
	p10.px = line.b.px - line.a.px;
	p10.py = line.b.py - line.a.py;
	normal = ft_normalize(point(-p10.py, p10.px));
	p0.px = (line.a.px + line.b.px) * 0.5f;
	p0.py = (line.a.py + line.b.py) * 0.5f;
	p1.px = p0.px + normal.px * 12.0f;
	p1.py = p0.py + normal.py * 12.0f;
	draw_line(p0, p1, img);
}
