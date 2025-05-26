/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:55:25 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:55:25 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	color_point(t_point point, t_color color)
{
	point.color = color;
	return (point);
}

t_point	point(float px, float py)
{
	t_point	result;

	result.px = px;
	result.py = py;
	result.pz = 0;
	result.color = color(black);
	return (result);
}
