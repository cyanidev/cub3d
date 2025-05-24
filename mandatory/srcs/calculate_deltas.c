/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_deltas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:27:34 by Andie             #+#    #+#             */
/*   Updated: 2025/05/24 02:34:30 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include <time.h>

void	calculate_deltas(t_player *plyr, t_point *dts, t_point *fov1, t_point *fov2)
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
}
