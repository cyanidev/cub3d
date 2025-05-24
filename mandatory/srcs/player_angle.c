/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:48 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 20:00:42 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

int	update_player_angle_from_angle(t_cub *cub, float angle)
{
	float	fov;

	cub->player->camera->angle = angle;
	fov = cub->player->camera->fov;
	fov = fov / 2.0f;
	cub->p_deltas.px = cos(deg2_rad(angle));
	cub->p_deltas.py = sin(deg2_rad(angle));
	cub->fov1_deltas.px = cos(deg2_rad(angle - fov));
	cub->fov1_deltas.py = sin(deg2_rad(angle - fov));
	cub->fov2_deltas.px = cos(deg2_rad(angle + fov));
	cub->fov2_deltas.py = sin(deg2_rad(angle + fov));
	return (1);
}

int	update_player_angle(t_player *player, t_point *deltas, t_angle *angle)
{
	if (!player)
		return (0);
	player->camera->angle = fix_angle(angle->angle);
	calculate_deltas(player, deltas, angle->fov1, angle->fov2);
	return (1);
}
