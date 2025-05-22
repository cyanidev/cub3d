/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:03 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 19:56:04 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include <time.h>

int	mouse_press(int key, int x, int y, void *param)
{
	t_cub		*cub;

	cub = (t_cub *)param;
	if (key == 1)
	{
		cub->mouse_press = 1;
		cub->last_mouse_grab = point(x, y);
	}
	if (cub->game_mode == EDITOR)
	{
		if (key == 5)
			cub->map_editor.screen_zoom -= 10;
		if (key == 4)
			cub->map_editor.screen_zoom += 10;
		if (cub->map_editor.screen_zoom <= 0)
			cub->map_editor.screen_zoom = 10;
		if (cub->map_editor.screen_zoom >= 150)
			cub->map_editor.screen_zoom = 150;
		printf("zoom:%d\n", cub->map_editor.screen_zoom);
	}
	return (1);
}

int	mouse_release(int key, int x, int y, void *param)
{
	t_cub		*cub;

	cub = (t_cub *)param;
	if (key == 1)
	{
		cub->mouse_press = 0;
		cub->last_mouse_grab = point(x, y);
	}
	return (1);
}

int	focus_in(void *param)
{
	t_cub		*cub;

	cub = (t_cub *)param;
	cub->focus = 1;
	return (1);
}

int	focus_out(void *param)
{
	t_cub		*cub;

	cub = (t_cub *)param;
	cub->focus = 0;
	return (1);
}
