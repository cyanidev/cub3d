/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_n_ground.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:40:18 by Andie             #+#    #+#             */
/*   Updated: 2025/05/17 13:05:31 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

void	draw_sky_and_ground(t_cub *cub, int wall_top,
		size_t wall_n, int wall_bottom)
{
	int		i;
	t_point	pixel;

	i = 0;
	pixel.px = (float)wall_n;
	while (i < wall_top)
	{
		pixel.py = (float)i;
		pixel.color = cub->ceiling;
		put_pixel(cub->game_img, pixel);
		i++;
	}
	i = wall_bottom;
	while (i < cub->main_window->res.height)
	{
		pixel.py = (float)i;
		pixel.color = cub->floor;
		put_pixel(cub->game_img, pixel);
		i++;
	}
}
