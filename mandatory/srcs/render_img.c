/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:43:20 by Andie             #+#    #+#             */
/*   Updated: 2025/05/24 04:59:45 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

void	put_img_to_render(t_img *img, t_img *render)
{
	unsigned int	x;
	unsigned int	y;
	float	x_prop;
	float	y_prop;
	float	aspect_ratio;
	t_point	pixel;

	y = 0;
	aspect_ratio = ((float)render->resolution.width
		/ (float)render->resolution.height);
	while (y < render->resolution.height)
	{
		x = 0;
		y_prop = (float)y / (float)render->resolution.height;
		while (x < render->resolution.width)
		{
			x_prop = (float)x / (float)render->resolution.width;
			
			pixel.color = color_from_hex(get_pixel_img(img, (float)img->resolution.width * x_prop, (((float)img->resolution.height / aspect_ratio) * y_prop) + ((float)img->resolution.width / 2.0f) - ((float)img->resolution.height / (aspect_ratio * 2))));
			pixel.px = (float)x;
			pixel.py = (float)y;
			put_pixel(render, pixel);
			x++;
		}
		y++;
	}
}
int	render_normal_mode(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->main_window->mlx_win, cub->game_img->img, 0, 0);
	return (0);
}

int	render_bonus_mode(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->main_window->mlx_win, cub->game_img->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->main_window->mlx_win, cub->minimap_img->img, 0, 0);
	return (0);
}
