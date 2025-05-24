/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:39:56 by Andie             #+#    #+#             */
/*   Updated: 2025/05/23 18:49:05 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

static t_point	set_end(t_img *img, t_map_editor editor)
{
	t_point	end;

	end = undo_remap_point(point(img->resolution.width,
				img->resolution.height), editor.screen_zoom,
			editor.screen_center, img->resolution);
	return (end);
}

static void
	set_tmp(t_point *tmp, t_map_editor editor, t_img *img, t_color color)
{
	*tmp = remap_point(*tmp, editor.screen_zoom,
			editor.screen_center, img->resolution);
	tmp->px = (unsigned int)tmp->px;
	tmp->py = (unsigned int)tmp->py;
	tmp->color = color;
}

int	draw_grid(t_map_editor editor, t_img *img, t_color color)
{
	t_point	end;
	t_point	start;
	t_point	tmp;
	int		i;
	int		j;

	end = set_end(img, editor);
	start = undo_remap_point(point(0, 0),
			editor.screen_zoom, editor.screen_center,
			img->resolution);
	j = (int)start.py;
	j -= 1;
	while (j < (int)end.py + 1)
	{
		i = (int)start.px - 1;
		while (i < (int)end.px + 1)
		{
			tmp = point((float)i, (float)j);
			set_tmp(&tmp, editor, img, color);
			put_pixel(img, tmp);
			i++;
		}
		j++;
	}
	return (1);
}
