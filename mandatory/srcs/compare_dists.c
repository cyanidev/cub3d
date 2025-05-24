/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_dists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:38:53 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:38:54 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

t_point	cmp_dists(t_point start, t_point *dist1, t_point *dist2, t_point *dist3)
{
	float	dista;
	float	distb;
	float	distc;
	float	result;

	distc = -1.0f;
	dista = distance_between_points(start, *dist1);
	if (dista < 0.0f)
		dista = dista * -1.0f;
	distb = distance_between_points(start, *dist2);
	if (distb < 0.0f)
		distb = distb * -1.0f;
	if (dist3)
		distc = distance_between_points(start, *dist3);
	if (dista < distb)
		result = dista;
	else
		result = distb;
	if (distc < result && distc != -1.0f)
		result = distc;
	if (result == dista)
		return (*dist1);
	if (result == distb)
		return (*dist2);
	return (*dist3);
}
