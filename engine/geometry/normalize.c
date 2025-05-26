/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:55:44 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:55:45 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "ft_math.h"

t_point	normalize(t_point point)
{
	t_point	result;
	float	inv_sqr;

	result = point;
	inv_sqr = q_rsqrt((point.px * point.px)
			+ (point.py * point.py) + (point.pz * point.pz));
	result.px = point.px * inv_sqr;
	result.py = point.py * inv_sqr;
	result.pz = point.pz * inv_sqr;
	return (result);
}
