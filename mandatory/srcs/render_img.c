/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:43:20 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 20:09:28 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

static void	set_pixel_color(t_point *pixel, t_img *img, t_helper *h)
{
	pixel->color = color_from_hex(get_pixel_img(img,
				(float)img->resolution.width * h->x_prop,
				(((float)img->resolution.height
						/ h->aspect_ratio) * h->y_prop)
				+ ((float)img->resolution.width / 2.0f)
				- ((float)img->resolution.height
					/ (h->aspect_ratio * 2))));
}

void	put_img_to_render(t_img *img, t_img *render)
{
	t_helper	h;
	t_point		pixel;

	h.y = 0;
	h.aspect_ratio = ((float)render->resolution.width
			/ (float)render->resolution.height);
	while ((float)h.y < render->resolution.height)
	{
		h.x = 0;
		h.y_prop = (float)h.y / (float)render->resolution.height;
		while ((float)h.x < render->resolution.width)
		{
			h.x_prop = (float)h.x / (float)render->resolution.width;
			set_pixel_color(&pixel, img, &h);
			pixel.px = (float)h.x;
			pixel.py = (float)h.y;
			put_pixel(render, pixel);
			h.x++;
		}
		h.y++;
	}
}

int	render_normal_mode(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx,
		cub->main_window->mlx_win, cub->game_img->img, 0, 0);
	return (1);
}

int	render_bonus_mode(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx,
		cub->main_window->mlx_win, cub->game_img->img, 0, 0);
	mlx_put_image_to_window(cub->mlx,
		cub->main_window->mlx_win, cub->minimap_img->img, 0, 0);
	return (1);
}
