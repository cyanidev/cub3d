/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cast_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:59:52 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 21:12:29 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include "cub_ray.h"

static t_ccr	init_ccr(t_cub *cub, float angle, float distance)
{
	t_ccr	ccr;

	ccr.result = new_cub_ray_obj();
	ccr.player = cub->player->camera->pos;
	ccr.ray = ccr.player;
	ccr.delta_x = cos(deg2_rad(angle));
	ccr.delta_y = sin(deg2_rad(angle));
	ccr.ray.px += ccr.delta_x * distance * 100;
	ccr.ray.py += ccr.delta_y * distance * 100;
	ccr.ray.pz = -1.0f;
	ccr.limits = check_limits_dda(angle);
	return (ccr);
}

static void	set_limits(t_cub *cub, t_ccr *ccr)
{
	if (ccr->limits == 1)
		ccr->tmp_ray1 = dda_calculate_x_right(cub, ccr->delta_x, ccr->delta_y);
	else if (ccr->limits == 2)
		ccr->tmp_ray1 = dda_calculate_y_down(cub, ccr->delta_x, ccr->delta_y);
	else if (ccr->limits == 3)
		ccr->tmp_ray1 = dda_calculate_x_left(cub, ccr->delta_x, ccr->delta_y);
	else if (ccr->limits == 4)
		ccr->tmp_ray1 = dda_calculate_y_up(cub, ccr->delta_x, ccr->delta_y);
	ccr->ray = cmp_dists(ccr->player, &(ccr->tmp_ray1), &(ccr->ray), NULL);
}

static void	set_rays(t_cub *cub, t_ccr *ccr, float angle)
{
	if (ccr->limits)
		set_limits(cub, ccr);
	else if ((int)angle < 90 && (int)angle > 0)
		ray_angle_zero_to_nineth(cub, ccr);
	else if ((int)angle > 270 && (int)angle < 360)
		ray_angle_two_seven_three_sixth(cub, ccr);
	else if (angle > 90.0f && angle < 180.0f)
		ray_angle_nineth_onehundred(cub, ccr);
	else if (angle > 180.0f && angle < 270.0f)
		ray_angle_onehundred_twohundred_seventh(cub, ccr);
}

static void	set_result(t_ccr *ccr)
{
	ccr->screen_dist = 0;
	ccr->hypo = distance_between_points(ccr->player, ccr->ray);
	ccr->result->x = (int)ccr->ray.px;
	ccr->result->real_x = ccr->ray.px;
	ccr->result->real_y = ccr->ray.py;
	ccr->result->y = (int)ccr->ray.py;
	ccr->result->dist = ccr->screen_dist;
	ccr->result->deltx = ccr->delta_x;
	ccr->result->delty = ccr->delta_y;
	ccr->result->real_dist = distance_between_points(ccr->ray, ccr->player);
}

t_cub_ray	*cub_cast_ray(t_cub *cub, float angle, float distance)
{
	t_ccr	ccr;

	ccr = init_ccr(cub, angle, distance);
	set_rays(cub, &ccr, angle);
	set_result(&ccr);
	if (ccr.ray.pz > -1.0f)
	{
		ccr.result->side = (int)ccr.ray.pz;
		ccr.result->hit = 1;
	}
	else
	{
		ccr.result->hit = 0;
		ccr.result->side = (int)ccr.ray.pz;
	}
	if (ccr.result->dist < distance)
		ccr.result->hit = 1;
	return (ccr.result);
}
