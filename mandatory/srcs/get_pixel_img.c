/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:28 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 21:31:25 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

int	get_pixel_img(t_img *img, int x, int y)
{
	if (x < 0 || x > img->resolution.width || y < 0
		|| y > img->resolution.height)
		return (color_from_rgb(255, 0, 255).hex);
	return (*(unsigned int *)((img->data_addr + \
	(y * img->line_size) + (x * img->bits_per_pixel / 8))));
}
