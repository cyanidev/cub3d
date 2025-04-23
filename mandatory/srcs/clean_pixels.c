/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:38:40 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:45:03 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "cub_ray.h"

int	slow_clean_pixels(long long *dest, t_resolution res)
{
	size_t	i;
	size_t	size;

	size = (res.height * res.width) / 2;
	i = 0;
	while (i < size)
	{
		if (dest[i])
			dest[i] = 0;
		i++;
	}
	return (1);
}

int	clean_pixels(t_img *img)
{
	slow_clean_pixels(img->data_addr, img->resolution);
}
