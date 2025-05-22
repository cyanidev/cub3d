/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:23:21 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 19:42:41 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

t_point	dda_calculate_x_right(t_cub *cub, float delta_x, float delta_y)
{
	t_point	result;
	t_point	player;
	int		map_check;
	float	dist;

	result.pz = 1.0f;
	player = cub->player->camera->pos;
	result.px = (float)((int)player.px + 1);
	result.px += 0.000001f;
	result.py = player.py + delta_y * (get_dist_delt(
				delta_x, result.px, player.px));
	map_check = dda_check_map(cub, result);
	if (map_check == 1)
		return (result);
	if (map_check == -1)
		return (result);
	dist = get_dist_delt(delta_x, result.px + 1.0f, result.px);
	while (!map_check)
	{
		result.py += delta_y * dist;
		result.px += delta_x * dist;
		map_check = dda_check_map(cub, result);
	}
	return (result);
}

t_point	dda_calculate_x_left(t_cub *cub, float delta_x, float delta_y)
{
	t_point	result;
	t_point	player;
	int		map_check;
	float	dist;

	result.pz = 3.0f;
	player = cub->player->camera->pos;
	result.px = (float)((int)player.px);
	result.px -= 0.000001f;
	result.py = player.py + delta_y * (get_dist_delt(
				delta_x, result.px, player.px));
	map_check = dda_check_map(cub, result);
	if (map_check == 1)
		return (result);
	if (map_check == -1)
		return (result);
	dist = get_dist_delt(delta_x, result.px - 1.0f, result.px);
	while (!map_check)
	{
		result.py += delta_y * dist;
		result.px += delta_x * dist;
		map_check = dda_check_map(cub, result);
	}
	return (result);
}
