/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:40:30 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 18:48:42 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "helper.h"

static void	set_rwall_color(t_point *pixel, t_rwall *rwall,
			t_img *texture, t_drwall *dw)
{
	pixel->color = color(WHITE);
	pixel->color = color_from_hex(get_pixel_img(texture,
				dw->real_pos_x
				* (float)texture->resolution.width,
				((float)dw->real_pos / rwall->wall_height)
				* (float)texture->resolution.height));
	if (rwall->ray->side == 1 || rwall->ray->side == 3)
		pixel->color = color_mix(pixel->color, color(BLACK), 0.75f);
	pixel->color = color_mix(pixel->color,
			color(BLACK), dw->color_mix_lerp);
}

static void
	render_wall(t_rwall *rwall, t_drwall *dw, t_point *pixel)
{
	t_img		*texture;

	texture = rwall->cub->test_tex;
	if (rwall->ray->side == 2)
		texture = rwall->cub->south;
	if (rwall->ray->side == 0)
		texture = rwall->cub->north;
	if (rwall->ray->side == 1)
		texture = rwall->cub->west;
	if (rwall->ray->side == 3)
		texture = rwall->cub->east;
	while (dw->y < dw->wall_bottom)
	{
		dw->real_pos = dw->y - dw->min_top;
		pixel->px = rwall->wall_n;
		pixel->py = (float)dw->y;
		set_rwall_color(pixel, rwall, texture, dw);
		rwall->tmp_color = pixel->color;
		put_pixel(rwall->cub->game_img, *pixel);
		dw->y++;
		dw->mirror_helper++;
	}
}

void	draw_wall(t_cub *cub, t_cub_ray *ray, t_dwall_helper *dh)
{
	t_point		pixel;
	t_drwall	dw;
	t_rwall		rwall;

	dw.res_height = cub->game_img->resolution.height;
	dw.wall_top = (int)(dw.res_height - (float)dh->wall_height) / 2;
	dw.min_top = dw.wall_top;
	dw.wall_bottom = dw.wall_top + dh->wall_height;
	if (dw.wall_top < 0)
		dw.wall_top = 0;
	if (dw.wall_bottom >= dw.res_height)
		dw.wall_bottom = (int)(dw.res_height - 1.0f);
	dw.color_mix_lerp = 4;
	if (dw.color_mix_lerp > 1)
		dw.color_mix_lerp = 1;
	draw_sky_and_ground(cub, dw.wall_top, dh->wall_n, dw.wall_bottom);
	dw.y = dw.wall_top;
	dw.real_pos_x = get_real_pos_x(ray->real_x, ray->real_y, ray->side);
	dw.mirror_helper = 0;
	rwall.cub = cub;
	rwall.ray = ray;
	rwall.wall_n = dh->wall_n;
	rwall.wall_height = (float)dh->wall_height;
	render_wall(&rwall, &dw, &pixel);
}
