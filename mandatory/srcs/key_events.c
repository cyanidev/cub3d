/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:50 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 19:54:57 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include <time.h>

int	key_press_game(int key, t_cub *cub)
{
	if (key && cub)
		return (1);
	return (1);
}

void	select_key_w_s_a_d_e_q(t_cub *cub, int key)
{
	if (key == XK_w)
		k_w(cub);
	if (key == XK_s)
		k_s(cub);
	if (key == XK_a)
		k_a(cub);
	if (key == XK_d)
		k_d(cub);
	if (key == XK_e)
		k_e(cub);
	if (key == XK_q)
		k_q(cub);
}

void	select_key_0_to_9(t_cub *cub, int key)
{
	if (key == XK_0)
		k_0(cub);
	if (key == XK_1)
		cub->height_multiplier -= 0.0001f;
	if (key == XK_2)
		cub->height_multiplier += 0.001f;
	if (key == XK_3)
		cub->wall_height -= 0.001f;
	if (key == XK_4)
		cub->wall_height += 0.001f;
	if (key == XK_5)
		cub->max_dist -= 0.01f;
	if (key == XK_6)
		cub->max_dist += 0.01f;
	if (key == XK_7)
		cub->ambient_occlusion += 0.01f;
	if (key == XK_8)
		cub->ambient_occlusion -= 0.01f;
	if (key == XK_9)
		k_9(cub);
}

int	key_press(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (key == XK_m)
	{
		if (cub->game_mode == GAME)
			return (editor_mode(cub));
		else
			return (game_mode(cub));
	}
	if (key == XK_Escape)
	{
		//free_parsing(cub, 0);
	}
	select_key_w_s_a_d_e_q(cub, key);
	select_key_0_to_9(cub, key);
	if (cub->game_mode == GAME)
		key_press_game(key, cub);
	if (cub->game_mode == EDITOR)
		key_press_editor(key, cub);
	return (1);
}
