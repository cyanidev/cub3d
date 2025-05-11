/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cast_ray_angles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:51:41 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/11 12:55:02 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "cub_ray.h"

void	ray_angle_zero_to_nineth(t_cub *cub, t_ccr *ccr)
{
	ccr->tmp_ray1 = dda_calculate_x_right(cub, ccr->delta_x, ccr->delta_y);
	ccr->tmp_ray2 = dda_calculate_y_down(cub, ccr->delta_x, ccr->delta_y);
	ccr->ray = cmp_dists(ccr->player, &(ccr->tmp_ray1), &(ccr->tmp_ray2),
			&(ccr->ray));
}

void	ray_angle_two_seven_three_sixth(t_cub *cub, t_ccr *ccr)
{
	ccr->tmp_ray1 = dda_calculate_x_right(cub, ccr->delta_x, ccr->delta_y);
	ccr->tmp_ray2 = dda_calculate_y_up(cub, ccr->delta_x, ccr->delta_y);
	ccr->ray = cmp_dists(ccr->player, &(ccr->tmp_ray1), &(ccr->tmp_ray2),
			&(ccr->ray));
}

void	ray_angle_nineth_onehundred(t_cub *cub, t_ccr *ccr)
{
	ccr->tmp_ray1 = dda_calculate_x_left(cub, ccr->delta_x, ccr->delta_y);
	ccr->tmp_ray2 = dda_calculate_y_down(cub, ccr->delta_x, ccr->delta_y);
	ccr->ray = cmp_dists(ccr->player, &(ccr->tmp_ray1), &(ccr->tmp_ray2),
			&(ccr->ray));
}

void	ray_angle_onehundred_twohundred_seventh(t_cub *cub, t_ccr *ccr)
{
	ccr->tmp_ray1 = dda_calculate_x_left(cub, ccr->delta_x, ccr->delta_y);
	ccr->tmp_ray2 = dda_calculate_y_up(cub, ccr->delta_x, ccr->delta_y);
	ccr->ray = cmp_dists(ccr->player, &(ccr->tmp_ray1), &(ccr->tmp_ray2),
			&(ccr->ray));
}
