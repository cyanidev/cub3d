/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_deltas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:27:34 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 19:42:24 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include <time.h>

int	calculate_deltas(t_player *plyr, t_point *dts, t_point *fov1, t_point *fov2)
{
	float	angle;
	float	fov;

	if (plyr)
	{
		angle = plyr->camera->angle;
		fov = plyr->camera->fov;
		fov = fov / 2.0f;
		dts->px = cos(deg2_rad(angle));
		dts->py = sin(deg2_rad(angle));
		fov1->px = cos(deg2_rad(angle - fov));
		fov1->py = sin(deg2_rad(angle - fov));
		fov2->px = cos(deg2_rad(angle + fov));
		fov2->py = sin(deg2_rad(angle + fov));
	}
	return (1);
}
