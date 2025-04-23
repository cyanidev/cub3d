/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:39:51 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:39:51 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

static void	horizontal_line(int x0, int y0, int x1, t_img *img, t_color color) //--> needs to be 4
{
	int x;

	x = x0;
	while (x <= x1)
	{
		++x;
		put_pixel(img, color_point(point(x, y0), color)); // find put_pixel
	}

}

static void	plot4points(int cx, int cy, int x, int y, t_img *img, t_color color) //--> needs to be 4
{
	horizontal_line(cx - x, cy + y, cx +x, img, color);
	if (y != 0)
		horizontal_line(cx - x, cy - y, cx +x, img, color);
}

void	draw_circle(int radius, t_img *img, t_point center)
{

	int	cx;
	int	cy;

	cx = center.px;
	cy = center.py;

	int error;
	int	x;
	int y;
	int	lasty;

	error = -radius;
	x = radius;
	y = 0;
	while (x >= y)
	{
			lasty = y;
			error += y++;
			error += y;
			plot4points(cx, cy, x, lasty, img, center.color);
			if (error >= 0)	
			{
				if (x != lasty)
					plot4points(cx, cy, lasty, x, img, center.color);
				error -= x--;
				error -= x;
			}
	}

}