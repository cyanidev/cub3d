/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:39:51 by Andie             #+#    #+#             */
/*   Updated: 2025/05/11 14:39:31 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

static void	horizontal_line(t_hline *hline, t_img *img, t_color color)
{
	int	x;

	x = hline->x0;
	while (x <= hline->x1)
	{
		++x;
		put_pixel(img,
			color_point(point(x, hline->y0), color));
	}
}

static void
	plot4points(t_dcircle *dcircle, int x, int y)
{
	t_hline	hline;

	hline.x0 = dcircle->cx - x;
	hline.y0 = dcircle->cy + y;
	hline.x1 = dcircle->cx + x;
	horizontal_line(&hline, dcircle->img, dcircle->color);
	if (y != 0)
	{
		hline.x0 = dcircle->cx - x;
		hline.y0 = dcircle->cy - y;
		hline.x1 = dcircle->cx + x;
		horizontal_line(&hline, dcircle->img, dcircle->color);
	}
}

void	draw_circle(int radius, t_img *img, t_point center)
{
	t_dcircle	dcircle;

	dcircle.cx = center.px;
	dcircle.cy = center.py;
	dcircle.error = -radius;
	dcircle.x = radius;
	dcircle.y = 0;
	dcircle.img = img;
	dcircle.color = center.color;
	while (dcircle.x >= dcircle.y)
	{
		dcircle.lasty = dcircle.y;
		dcircle.error += dcircle.y++;
		dcircle.error += dcircle.y;
		plot4points(&dcircle, dcircle.x, dcircle.lasty);
		if (dcircle.error >= 0)
		{
			if (dcircle.x != dcircle.lasty)
				plot4points(&dcircle, dcircle.lasty,
					dcircle.x);
			dcircle.error -= dcircle.x--;
			dcircle.error -= dcircle.x;
		}
	}
}
