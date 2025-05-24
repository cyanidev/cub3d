/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:32:03 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/24 15:32:47 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include "engine.h"
#include <time.h>

void	check_program_args(int argc)
{
	if (argc != 2)
	{
		if (write(2, "Error: wrong number of arguments\n", 34) == -1)
			exit (-1);
		exit (-1);
	}
}

void	set_img_and_hooks(t_cub *cub)
{
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
	cub->game_img = init_img(cub->mlx,
			resolution(cub->main_window->res.height,
				cub->main_window->res.height));
	if (!cub->game_img)
	{
		printf("error pls fix\n");
		exit(-1);
	}
	cub->minimap_img = init_img(cub->mlx, resolution(
				cub->main_window->res.height * 0.1,
				cub->main_window->res.height * 0.1));
}
