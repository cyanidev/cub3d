/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_calcs_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:36:18 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/17 15:37:12 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include <time.h>

int	key_press_editor(int key, t_cub *cub)
{
	if (key == 65362)
		cub->map_editor.screen_center.py += 100 * cub->delta_time;
	if (key == 65363)
		cub->map_editor.screen_center.px -= 100 * cub->delta_time;
	if (key == 65364)
		cub->map_editor.screen_center.py -= 100 * cub->delta_time;
	if (key == 65361)
		cub->map_editor.screen_center.px += 100 * cub->delta_time;
}

void	k_e(t_cub *cub)
{
	update_player_angle(cub->player,
		&cub->p_deltas, &cub->fov1_deltas, &cub->fov2_deltas,
		cub->player->camera->angle + 100.0 * cub->delta_time);
	cub->fov1_screen.px = cub->player->camera->pos.px
		* cub->fov1_deltas.px * cub->fov1_screen.pz;
	cub->fov1_screen.py = cub->player->camera->pos.py
		* cub->fov1_deltas.py * cub->fov1_screen.pz;
	cub->fov2_screen.px = cub->player->camera->pos.px
		* cub->fov2_deltas.px * cub->fov2_screen.pz;
	cub->fov2_screen.py = cub->player->camera->pos.py
		* cub->fov2_deltas.py * cub->fov2_screen.pz;
}

void	k_q(t_cub *cub)
{
	update_player_angle(cub->player, &cub->p_deltas,
		&cub->fov1_deltas, &cub->fov2_deltas,
		cub->player->camera->angle - 100.0 * cub->delta_time);
	cub->fov1_screen.px = cub->player->camera->pos.px
		* cub->fov1_deltas.px * cub->fov1_screen.pz;
	cub->fov1_screen.py = cub->player->camera->pos.py
		* cub->fov1_deltas.py * cub->fov1_screen.pz;
	cub->fov2_screen.px = cub->player->camera->pos.px
		* cub->fov2_deltas.px * cub->fov2_screen.pz;
	cub->fov2_screen.py = cub->player->camera->pos.py
		* cub->fov2_deltas.py * cub->fov2_screen.pz;
}

void	k_0(t_cub *cub)
{
	cub->player->camera->fov -= 1.0f;
	cub->player->camera->pos.pz = cub->player->camera->fov
		* cub->height_multiplier;
	update_player_angle(cub->player, &cub->p_deltas, &cub->fov1_deltas,
		&cub->fov2_deltas, cub->player->camera->angle);
}

void	k_9(t_cub *cub)
{
	cub->player->camera->fov += 1.0f;
	cub->player->camera->pos.pz = cub->player->camera->fov
		* cub->height_multiplier;
	update_player_angle(cub->player, &cub->p_deltas,
		&cub->fov1_deltas, &cub->fov2_deltas,
		cub->player->camera->angle);
}
