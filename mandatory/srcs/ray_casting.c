/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:43:04 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:43:05 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

void	draw_walls_from_ray(float max_dist, size_t ray_n, float angle, t_cub *cub, t_cub_ray *ray)
{
	t_point	tmp;
	int		wall_height;
	float	dist;
	float	tmp2;
	float	res_height;
	double	last_time;

	if (!ray)
		return ;

	res_height = (float)cub->game_img->resolution.height;
	tmp = cub->player->camera->pos;
	dist = ray->real_dist;
	dist = cub->player->camera->angle - angle;
	dist = deg2_rad(dist);
	dist = ray->real_dist * cos(dist);

	tmp2 = cub->player->camera->pos.pz;
	dist	= dist / tmp2;
	dist = res_height / dist;
	wall_height = (int)dist;

	if (cub->game_mode == GAME)
		draw_wall(max_dist, wall_height, cub, ray_n, ray, angle);

	ray->del(ray);
}


int	ray_casting(t_cub *cub, t_map_editor minimap)
{
	size_t	number_of_rays;
	size_t	iterator;
	float	start_angle;
	float	multiplier;
	float	max_dist;

	number_of_rays = cub->game_img->resolution.width;
	multiplier = (float)cub->player->camera->fov / (float)number_of_rays;
	start_angle = cub->player->camera->angle;
	start_angle = start_angle - (cub->player->camera->fov / 2.0f);
	iterator = 0;
	max_dist = cub->max_dist;
	while (iterator < number_of_rays)
	{
		draw_walls_from_ray(max_dist, iterator, start_angle, cub, cub_cast_ray(cub, fix_angle(start_angle), max_dist, minimap));

		// angle
		start_angle += multiplier;
		// x
		iterator++;
	}
}