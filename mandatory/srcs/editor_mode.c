/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:21:13 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 21:23:52 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

int	editor_mode(t_cub *cub)
{
	if (cub->game_mode != EDITOR)
	{
		mlx_put_image_to_window(cub->mlx, cub->main_window->mlx_win,
			cub->editor_img->img, 0, 0);
		fill_img(cub->editor_img, color_from_rgb(0, 0, 0));
	}
	cub->game_mode = EDITOR;
	if (cub->mouse_press)
		cub->map_editor.screen_center = mouse_pos_relative(cub,
				cub->main_window);
	clean_pixels(cub->editor_img);
	mlx_mouse_show(cub->mlx, cub->main_window->mlx_win);
	draw_grid(cub->map_editor, cub->editor_img, color_from_rgb(100, 100, 100));
	//draw_fov_intersection(cub, cub->map_editor, color_from_rgb(255, 0, 255), cub->editor_img);
	draw_map_walls(cub, cub->map_editor, cub->editor_img);
	ray_casting(cub, cub->map_editor);
	draw_player(cub, cub->map_editor, color_from_rgb(255, 255, 0),
		cub->editor_img);
	mlx_put_image_to_window(cub->mlx, cub->main_window->mlx_win,
		cub->editor_img->img, 0, 0);
}
