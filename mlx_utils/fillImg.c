/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillImg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:58:13 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:58:13 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	fill_img(t_img *img, t_color color)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i != img->resolution.height)
	{
		j = 0;
		while (j != img->resolution.width)
		{
			put_pixel(img, color_point(point(j, i), color));
			++j;
		}
		i++;
	}
}
