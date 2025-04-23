/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:36:07 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:37:22 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

t_point	dda_calculate_y_down(t_cub *cub, float delta_x, float delta_y)
{
	t_point	result;
	t_point	player;
	int		map_check;
	float	dist;

	result.pz = 2.0f;
	player = cub->player->camera->pos;
	result.py = (float)((int)player.py + 1.0f);
	result.py += 0.000001f;
	result.px = player.px + delta_x * (get_dist_delt
			(delta_y, result.py, player.py));
	map_check = dda_check_map(cub, result);
	if (map_check == 1)
		return (result);
	if (map_check == -1)
		return (result);
	dist = get_dist_delt(delta_y, result.py + 1.0f, result.py);
	while (!map_check)
	{
		result.py += delta_y * dist;
		result.px += delta_x * dist;
		map_check = dda_check_map(cub, result);
	}
	return (result);
}

t_point	dda_calculate_y_up(t_cub *cub, float delta_x, float delta_y)
{
	t_point	result;
	t_point	player;
	int		map_check;
	float	dist;

	result.pz = 0.0f;
	player = cub->player->camera->pos;
	result.py = (float)((int)player.py);
	result.py -= 0.000001f;
	result.px = player.px + delta_x * (get_dist_delt
			(delta_y, result.py, player.py));
	map_check = dda_check_map(cub, result);
	if (map_check == 1)
		return (result);
	if (map_check == -1)
		return (result);
	dist = get_dist_delt(delta_y, result.py - 1.0f, result.py);
	while (!map_check)
	{
		result.py += delta_y * dist;
		result.px += delta_x * dist;
		map_check = dda_check_map(cub, result);
	}
	return (result);
}
