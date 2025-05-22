/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:40:30 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 17:58:07 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

typedef struct s_drwall
{
	int		wall_top;
	int		min_top;
	int		wall_bottom;
	int		y;
	int		real_pos;
	int		mirror_y;
	int		mirror_helper;
	float	color_mix_lerp;
	float	real_pos_x;
	float	res_height;
}		t_drwall;

typedef struct s_rwall
{
	t_cub		*cub;
	t_cub_ray	*ray;
	t_color		tmp_color;
	float		wall_n;
	float		wall_height;
}		t_rwall;

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
		pixel->color	= color(WHITE);
		pixel->color = color_from_hex(get_pixel_img(texture,
				dw->real_pos_x
					* (float)texture->resolution.width,
				((float)dw->real_pos / rwall->wall_height)
					* (float)texture->resolution.height));
		if (rwall->ray->side == 1 || rwall->ray->side == 3)
			pixel->color = color_mix(pixel->color, color(BLACK), 0.75f);
		pixel->color = color_mix(pixel->color, color(BLACK), dw->color_mix_lerp);
		rwall->tmp_color = pixel->color;
		put_pixel(rwall->cub->game_img, *pixel);
		dw->y++;
		dw->mirror_helper++;
	}
}

void	draw_wall(float max_dist, int wall_height, t_cub *cub, size_t wall_n, t_cub_ray *ray, float angle)
{
	t_point		pixel;
	t_drwall	dw;
	t_rwall		rwall;

	dw.res_height = cub->game_img->resolution.height;
	dw.wall_top = (int)(dw.res_height - (float)wall_height) / 2;
	dw.min_top = dw.wall_top;
	dw.wall_bottom = dw.wall_top + wall_height;
	if (dw.wall_top < 0)
		dw.wall_top = 0;
	if (dw.wall_bottom >= dw.res_height) 
		dw.wall_bottom = (int)(dw.res_height - 1.0f);
	dw.color_mix_lerp *= 4;
	if (dw.color_mix_lerp > 1)
		dw.color_mix_lerp = 1;
	draw_sky_and_ground(cub, dw.wall_top, wall_n, dw.wall_bottom);
	dw.y = dw.wall_top;
	dw.real_pos_x = get_real_pos_x(ray->real_x, ray->real_y, ray->side);
	dw.mirror_helper = 0;
	rwall.cub = cub;
	rwall.ray = ray;
	rwall.wall_n = wall_n;
	rwall.wall_height = (float)wall_height;
	render_wall(&rwall, &dw, &pixel);
}
