/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:59:40 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 23:54:45 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

/*
	pixel_i = pixel index;
*/
void	put_pixel(t_img *img, t_point pixel)
{
	unsigned int	*dst;
	float			pixel_i;

	if (pixel.px >= 0 && pixel.py >= 0 && pixel.px < img->resolution.width && \
	pixel.py < img->resolution.height && pixel.py)
	{
		pixel_i = ((pixel.py * img->line_size) + \
		((pixel.px * (img->bits_per_pixel / 8))));
		dst = (unsigned int *)(img->data_addr + (int)pixel_i);
		*dst = pixel.color.hex;
	}
}
