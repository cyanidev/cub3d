/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:57 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 22:06:24 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

int	print_map_cub(t_cub *cub)
{
	char	c;
	int		x;
	int		y;

	x = 0;
	y = 0;
	printf("map start...%d\n");
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[0][x])
		{
			c = cub->map[y][x];
			printf("%c ", c);
			x++;
		}
		printf("$\n");
		y++;
	}
}

int	draw_map_walls(t_cub *cub, t_map_editor editor, t_img *img)
{
	t_point	tmp;
	size_t	x;
	size_t	y;

	y = 0;
	printf("\n\n the map...\n");
	print_map_cub(cub);
	printf("\n\n the map...\n");
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '1')
			{
				tmp = remap_point(point(x, y), 
					editor.screen_zoom, editor.screen_center, 
					img->resolution);
				tmp.color = color(WHITE);
				put_pixel(img, tmp);
				draw_square(editor.screen_zoom + 1, img, tmp);
			}
			x++;
		}
		y++;
	}
	return (1);
}
