/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:15:29 by afelicia          #+#    #+#             */
/*   Updated: 2025/05/24 13:29:56 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "engine.h"
#include <time.h>




t_map_editor	map_editor()
{
	t_map_editor	result;

	result.screen_center = point(0, 0);
	result.screen_zoom = 100;
	return (result);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
	{
		write(2, "Error: wrong number of arguments\n", 34);
		exit (-1);
	}
	cub = ft_constructor(argv[1], argv);
	if (!cub)
	{
		write(2, "Error: cannot initialize the general struct\n", 45);
		return (-1);
	}

	cub->main_window = new_window(cub->mlx, resolution(1000, 1000), "main_window");

	if (!cub->main_window)
	{
		printf("error pls fix this after\n");
		exit(-1);
	}

	start_hooks_in_window(cub->main_window, win_hooks(
	hooks(mouse_press, mouse_release),
	hooks(key_press, NULL),
	hooks(focus_in, focus_out)), cub);

	cub->editor_img = init_img(cub->mlx, cub->main_window->res);
	if (!cub->editor_img)
	{
		printf("error pls fix this after\n");
		exit(-1);
	}

	cub->game_img = init_img(cub->mlx, resolution(cub->main_window->res.height, cub->main_window->res.height));
	if (!cub->game_img)
	{
		printf("error pls fix\n");
		exit(-1);

	}

	cub->minimap_img = init_img(cub->mlx, resolution(
		cub->main_window->res.height * 0.1, cub->main_window->res.height * 0.1));

	// this part is parsing one map ======================================================

	printf("map:%p\n", cub->map);

	cub->map_editor = map_editor();
	cub->game_mode = GAME;
	cub->player = new_player(NULL);
	calculate_deltas(cub->player, &cub->p_deltas, &cub->fov1_deltas, &cub->fov2_deltas);
	// make screen limits
	cub->fov1_screen.pz = (float)(((float)(cub->main_window->res.width + 2) / 4.0f)) / cub->fov1_deltas.px;
	cub->fov2_screen.pz = cub->fov1_screen.pz;
	cub->fov1_screen.px = cub->player->camera->pos.px + (cub->fov1_deltas.px * cub->fov1_screen.pz);
	cub->fov1_screen.py = cub->player->camera->pos.py + (cub->fov1_deltas.py * cub->fov1_screen.pz);
	cub->fov2_screen.px = cub->player->camera->pos.px + (cub->fov2_deltas.px * cub->fov2_screen.pz);
	cub->fov2_screen.py = cub->player->camera->pos.py + (cub->fov2_deltas.py * cub->fov2_screen.pz);
	cub->fov1_screen.color = color(WHITE);
	cub->fov2_screen.color = color(WHITE);
	// make screen limits
	cub->test_tex = open_img(cub->mlx, "./srcs/side.xpm");

	mlx_put_image_to_window(cub->mlx, cub->main_window->mlx_win, cub->editor_img->img, 0, 0);


	cub->player->camera->pos.px = cub->parsing_px;
	cub->player->camera->pos.py = cub->parsing_py;

	cub->player->camera->fov = 46;

	cub->wall_height = 2.0f;

	cub->height_multiplier = 0.027255f;

	cub->player->camera->pos.pz = cub->player->camera->fov * cub->height_multiplier;//0.0576f;
	//cub->player->camera->pos.pz = 17;//0.0576f;
	printf("anlgeeee: %f\n", cub->player_angle);
	update_player_angle(cub->player, &cub->p_deltas, &cub->fov1_deltas, &cub->fov2_deltas, cub->player_angle);

	
	cub->ambient_occlusion = 0.875;
	cub->near_plane = 0.0f;
	cub->max_dist = 1.684f;

	cub->game_mode = GAME;
	// here goes the real angle and the real camera

	mlx_loop_hook(cub->mlx, frame, cub);
	mlx_loop(cub->mlx);
}
