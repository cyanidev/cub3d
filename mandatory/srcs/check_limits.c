/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:38:14 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:38:22 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

int	check_limits_dda_util(float angle)
{
	if (angle == 0)
		return (1);
	if (angle == 90)
		return (2);
	if (angle == 180)
		return (3);
	if (angle == 270)
		return (4);
	return (0);
}

int	check_limits_dda(float angle)
{
	int	angle_m;
	int	result;

	angle_m = (int)(angle);
	result = check_limits_dda_util(angle_m);
	return (result);
}
