/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:38:46 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:45:25 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

int	ft_get_color(int color, int col)
{
	if (col == 0)
		return ((color >> 24) & 0xFF);
	if (col == 1)
		return ((color >> 16) & 0xFF);
	if (col == 2)
		return ((color >> 8) & 0xFF);
	if (col == 3)
		return ((color) & 0xFF);
	return (0);
}

t_color	color_from_hex(int hex)
{
	t_color	result;

	result.r = ft_get_color(hex, 1);
	result.g = ft_get_color(hex, 2);
	result.b = ft_get_color(hex, 3);
	result.alpha = (float)ft_get_color(hex, 0) / 255.0f;
	result.hex = hex;
	return (result);
}
