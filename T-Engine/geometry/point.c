/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:16:55 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/07 13:19:08 by samusanc         ###   ########.fr       */
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
