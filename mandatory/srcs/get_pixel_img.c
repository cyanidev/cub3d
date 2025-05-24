/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:28 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 19:53:39 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

int	get_pixel_img(t_img *img, int x, int y)
{
	if (x < 0 || x > (int)img->resolution.width || y < 0
		|| y > (int)img->resolution.height)
		return (color_from_rgb(255, 0, 255).hex);
	return (*(unsigned int *)((img->data_addr + \
	(y * img->line_size) + (x * img->bits_per_pixel / 8))));
}
