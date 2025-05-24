/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:35 by Andie             #+#    #+#             */
/*   Updated: 2025/05/24 13:11:48 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

float	get_real_pos_x(float x, float y, int side)
{
	float	tmp;

	if (side == 0 || side == 2)
	{
		tmp = (int)x;
		if (side == 0)
			return (x - tmp);
		else
			return (1.0f - (x - tmp));
	}
	tmp = (int)y;
	if (side == 1)
		return (y - tmp);
	else
		return (1.0f - (y - tmp));
}
