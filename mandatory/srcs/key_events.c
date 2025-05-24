/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:50 by Andie             #+#    #+#             */
/*   Updated: 2025/05/24 04:47:23 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include <time.h>

/*static void key_press_editor(int key, t_cub *cub)
{
	if (key == 65362)
		cub->map_editor.screen_center.py += 100 * cub->delta_time;
	if (key == 65363)
		cub->map_editor.screen_center.px -= 100 * cub->delta_time;
	if (key == 65364)
		cub->map_editor.screen_center.py -= 100 * cub->delta_time;
	if (key == 65361)
		cub->map_editor.screen_center.px += 100 * cub->delta_time;
}*/

int	key_press(int key, void *param)
{
	t_cub		*cub;

	cub = (t_cub *)param;
	printf("super gofy key:%d\n", key);
	if (key == XK_Escape)
	{
		free_gen_struct(cub); //fix this
		exit(0);
	}
	if (key == XK_w)
	{
		cub->player->camera->pos.px += 1.0 * cub->p_deltas.px * cub->delta_time;
		cub->player->camera->pos.py += 1.0 * cub->p_deltas.py * cub->delta_time;	
	}
	if (key == XK_s)
	{
		cub->player->camera->pos.px -= 1.0 * cub->p_deltas.px * cub->delta_time;
		cub->player->camera->pos.py -= 1.0 * cub->p_deltas.py * cub->delta_time;	
	}
	if (key == XK_a)
	{
		cub->player->camera->pos.px += 1.0 * cub->p_deltas.py * cub->delta_time;
		cub->player->camera->pos.py -= 1.0 * cub->p_deltas.px * cub->delta_time;	
	}
	if (key == XK_d)
	{
		cub->player->camera->pos.px -= 1.0 * cub->p_deltas.py * cub->delta_time;
		cub->player->camera->pos.py += 1.0 * cub->p_deltas.px * cub->delta_time;	
	}
	if (key == XK_e)
	{
		update_player_angle(cub->player, &cub->p_deltas, &cub->fov1_deltas, &cub->fov2_deltas, 
		cub->player->camera->angle + 100.0 * cub->delta_time);
		cub->fov1_screen.px = cub->player->camera->pos.px * cub->fov1_deltas.px * cub->fov1_screen.pz;
		cub->fov1_screen.py = cub->player->camera->pos.py * cub->fov1_deltas.py * cub->fov1_screen.pz;

		cub->fov2_screen.px = cub->player->camera->pos.px * cub->fov2_deltas.px * cub->fov2_screen.pz;
		cub->fov2_screen.py = cub->player->camera->pos.py * cub->fov2_deltas.py * cub->fov2_screen.pz;
		printf("screen width:%f\n", distance_between_points(cub->fov1_screen, cub->fov2_screen));

	}
	if (key == XK_q)
	{
		update_player_angle(cub->player, &cub->p_deltas, &cub->fov1_deltas, &cub->fov2_deltas, 
		cub->player->camera->angle - 100.0 * cub->delta_time);

		cub->fov1_screen.px = cub->player->camera->pos.px * cub->fov1_deltas.px * cub->fov1_screen.pz;
		cub->fov1_screen.py = cub->player->camera->pos.py * cub->fov1_deltas.py * cub->fov1_screen.pz;

		cub->fov2_screen.px = cub->player->camera->pos.px * cub->fov2_deltas.px * cub->fov2_screen.pz;
		cub->fov2_screen.py = cub->player->camera->pos.py * cub->fov2_deltas.py * cub->fov2_screen.pz;
		printf("screen width:%f\n", distance_between_points(cub->fov1_screen, cub->fov2_screen));
	}
	if (key == XK_0)
	{
		cub->player->camera->fov -= 1.0f;
		cub->player->camera->pos.pz = cub->player->camera->fov * cub->height_multiplier;//0.0576f;
		update_player_angle(cub->player, &cub->p_deltas, &cub->fov1_deltas, &cub->fov2_deltas, cub->player->camera->angle);

	}
	if (key == XK_9)
	{
		cub->player->camera->fov += 1.0f;
		cub->player->camera->pos.pz = cub->player->camera->fov * cub->height_multiplier;//0.0576f;
		update_player_angle(cub->player, &cub->p_deltas, &cub->fov1_deltas, &cub->fov2_deltas, cub->player->camera->angle);
	}
	return (0);
}