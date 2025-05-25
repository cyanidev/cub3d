/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Q_rsqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:57:26 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:57:27 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Q_rsqrt.h"

float	q_rsqrt(float number)
{
	long		i;
	float		x2;
	float		y;
	const float	threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&number;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}
