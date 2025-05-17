/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:40:30 by Andie             #+#    #+#             */
/*   Updated: 2025/05/17 13:05:33 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

void draw_wall(float max_dist, int wall_height, t_cub *cub, size_t wall_n, t_cub_ray *ray, float angle)
{
	float	res_height;
    int		wall_top;
	int		min_top;
    int		wall_bottom;
	t_point	pixel;
	float	color_mix_lerp;
	int		y;
	int		real_pos;
	float	real_pos_x;
	int		mirror_y;
	int		mirror_helper;
	t_img	*texture;

	res_height = cub->game_img->resolution.height;
	wall_top = (int)(res_height - (float)wall_height) / 2;
	min_top = wall_top;
	wall_bottom = wall_top + wall_height;
    if (wall_top < 0)
		wall_top = 0;
    if (wall_bottom >= res_height) 
		wall_bottom = (int)(res_height - 1.0f);
	color_mix_lerp *= 4;
	if (color_mix_lerp > 1)
		color_mix_lerp = 1;
	draw_sky_and_ground(cub, wall_top, wall_n, wall_bottom);
	y = wall_top;
	real_pos_x = get_real_pos_x(ray->real_x, ray->real_y, ray->side);
	mirror_helper = 0;
	texture = cub->test_tex;
	if (ray->side == 2)
		texture = cub->south;
	if (ray->side == 0)
		texture = cub->north;
	if (ray->side == 1)
		texture = cub->west;
	if (ray->side == 3)
		texture = cub->east;

	while (y < wall_bottom)
	{
		real_pos = y - min_top;
		pixel.px = (float)wall_n;
		pixel.py = (float)y;
		pixel.color	= color(WHITE);
		pixel.color = color_from_hex(get_pixel_img(texture, real_pos_x * (float)texture->resolution.width, ((float)real_pos / (float)wall_height) * (float)texture->resolution.height));

		if (ray->side == 1 || ray->side == 3)
			pixel.color = color_mix(pixel.color, color(BLACK), 0.75f);
		pixel.color = color_mix(pixel.color, color(BLACK), color_mix_lerp);

		t_color	tmp_color;
		t_color	tmp_color2;
		//tmp_color = color_from_hex(get_pixel_img(cub->test_tex, real_pos_x * (float)cub->test_tex->resolution.width, ((float)real_pos / (float)wall_height) * (float)cub->test_tex->resolution.height));
	//	pixel.color = color_mix(pixel.color, tmp_color, 0.5f);

		tmp_color = pixel.color;


	//	tmp_color2 = color_from_hex(get_pixel_img(cub->test_tex, real_pos_x * (float)cub->test_tex->resolution.width, ((float)real_pos / (float)wall_height) * (float)cub->test_tex->resolution.height));
	//	pixel.color = color_mix(color(BLACK), tmp_color2, ((float)pixel.color.r / 255.0f));

		put_pixel(cub->game_img, pixel);

	//	tmp_color = pixel.color;
		

		y++;
		mirror_helper++;
	}
}
