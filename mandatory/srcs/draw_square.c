/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:40:24 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 21:20:25 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

int	draw_square(size_t length, t_img *img, t_point start)
{
	size_t	i;
	size_t	j;
	size_t	start_x;
	size_t	start_y;

	i = 0;
	j = 0;
	start_x = (size_t)start.px;
	while (i < length)
	{
		j = 0;
		start.px = start_x;
		while (j < length)
		{
			put_pixel(img, start);
			j++;
			start.px++;
		}
		i++;
		start.py++;
	}
	return (1);
}
