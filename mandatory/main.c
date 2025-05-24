/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:15:29 by afelicia          #+#    #+#             */
/*   Updated: 2025/05/24 15:34:19 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "engine.h"
#include <time.h>

t_map_editor	map_editor(void)
{
	t_map_editor	result;

	result.screen_center = point(0, 0);
	result.screen_zoom = 100;
	return (result);
}

void	set_cub_screen(t_cub *cub)
{
	cub->map_editor = map_editor();
	cub->game_mode = GAME;
	cub->player = new_player(NULL);
	calculate_deltas(cub->player,
		&cub->p_deltas, &cub->fov1_deltas, &cub->fov2_deltas);
	cub->fov1_screen.pz = (float)(((float)(cub->main_window->res.width + 2)
				/ 4.0f)) / cub->fov1_deltas.px;
	cub->fov2_screen.pz = cub->fov1_screen.pz;
	cub->fov1_screen.px = cub->player->camera->pos.px
		+ (cub->fov1_deltas.px * cub->fov1_screen.pz);
	cub->fov1_screen.py = cub->player->camera->pos.py
		+ (cub->fov1_deltas.py * cub->fov1_screen.pz);
	cub->fov2_screen.px = cub->player->camera->pos.px
		+ (cub->fov2_deltas.px * cub->fov2_screen.pz);
	cub->fov2_screen.py = cub->player->camera->pos.py
		+ (cub->fov2_deltas.py * cub->fov2_screen.pz);
	cub->fov1_screen.color = color(WHITE);
	cub->fov2_screen.color = color(WHITE);
	cub->test_tex = open_img(cub->mlx, "./srcs/side.xpm");
}

void	set_cub_data(t_cub **cub, char **argv)
{
	*cub = ft_constructor(argv);
	if (!(*cub))
	{
		if (write(2, "Error: cannot initialize the general struct\n", 45) == -1)
			exit(1);
		exit(1);
	}
	(*cub)->main_window = new_window((*cub)->mlx,
			resolution(1000, 1000), "main_window");
	if (!(*cub)->main_window)
	{
		free_gen_struct(*cub);
		exit(-1);
	}
}

void	set_cub_player(t_cub *cub)
{
	cub->player->camera->pos.px = cub->parsing_px;
	cub->player->camera->pos.py = cub->parsing_py;
	cub->player->camera->fov = 46;
	cub->wall_height = 2.0f;
	cub->height_multiplier = 0.027255f;
	cub->player->camera->pos.pz = cub->player->camera->fov
		* cub->height_multiplier;
}

int	main(int argc, char **argv)
{
	t_cub	*cub;
	t_angle	angle;

	check_program_args(argc);
	set_cub_data(&cub, argv);
	set_img_and_hooks(cub);
	set_cub_screen(cub);
	mlx_put_image_to_window(cub->mlx,
		cub->main_window->mlx_win, cub->editor_img->img, 0, 0);
	set_cub_player(cub);
	angle.fov1 = &cub->fov1_deltas;
	angle.fov2 = &cub->fov2_deltas;
	angle.angle = cub->player_angle;
	update_player_angle(cub->player, &cub->p_deltas, &angle);
	cub->ambient_occlusion = 0.875;
	cub->near_plane = 0.0f;
	cub->max_dist = 1.684f;
	cub->game_mode = GAME;
	mlx_loop_hook(cub->mlx, frame, cub);
	mlx_loop(cub->mlx);
	return (0);
}
