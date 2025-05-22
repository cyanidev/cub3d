/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:43:04 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 18:51:55 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "helper.h"

void	draw_walls_from_ray(t_rcast *r, t_cub *cub, t_cub_ray *ray)
{
	t_point			tmp;
	t_dwall			dwall;
	t_dwall_helper	dwl_helper;

	if (!ray)
		return ;
	dwall.res_height = (float)cub->game_img->resolution.height;
	tmp = cub->player->camera->pos;
	dwall.dist = ray->real_dist;
	dwall.dist = cub->player->camera->angle - r->start_angle;
	dwall.dist = deg2_rad(dwall.dist);
	dwall.dist = ray->real_dist * cos(dwall.dist);
	dwall.tmp2 = cub->player->camera->pos.pz;
	dwall.dist = dwall.dist / dwall.tmp2;
	dwall.dist = dwall.res_height / dwall.dist;
	dwall.wall_height = (int)dwall.dist;
	dwl_helper.max_dist = r->max_dist;
	dwl_helper.wall_height = dwall.wall_height;
	dwl_helper.wall_n = r->iterator;
	dwl_helper.angle = r->start_angle;
	if (cub->game_mode == GAME)
		draw_wall(cub, ray, &dwl_helper);
	ray->del(ray);
}

int	ray_casting(t_cub *cub, t_map_editor minimap)
{
	t_rcast	r;

	r.number_of_rays = cub->game_img->resolution.width;
	r.multiplier = cub->player->camera->fov / (float)r.number_of_rays;
	r.start_angle = cub->player->camera->angle;
	r.start_angle = r.start_angle - (cub->player->camera->fov / 2.0f);
	r.iterator = 0;
	r.max_dist = cub->max_dist;
	while (r.iterator < r.number_of_rays)
	{
		draw_walls_from_ray(&r, cub,
			cub_cast_ray(cub,
				fix_angle(r.start_angle),
				r.max_dist, minimap));
		r.start_angle += r.multiplier;
		r.iterator++;
	}
}
