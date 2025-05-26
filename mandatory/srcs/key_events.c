/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:50 by Andie             #+#    #+#             */
/*   Updated: 2025/05/26 18:18:03 by afelicia         ###   ########.fr       */
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

void	select_key_w_s_a_d_l_r(t_cub *cub, int key)
{
	if (key == XK_w)
		k_w(cub);
	if (key == XK_s)
		k_s(cub);
	if (key == XK_a)
		k_a(cub);
	if (key == XK_d)
		k_d(cub);
	if (key == XK_Right)
		k_e(cub);
	if (key == XK_Left)
		k_q(cub);
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
		free_cub(&cub);
		exit(1);
	}
	select_key_w_s_a_d_l_r(cub, key);
	if (cub->game_mode == GAME)
		key_press_game(key, cub);
	if (cub->game_mode == EDITOR)
		key_press_editor(key, cub);
	return (1);
}
