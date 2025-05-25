/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:54:24 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:54:24 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "color.h"

typedef struct s_point
{
	float	px;
	float	py;
	float	pz;
	t_color	color;
}		t_point;

// point is a 2d representation of a vector
t_point	point(float px, float py);

t_point	color_point(t_point point, t_color color);

t_point	vector(float px, float py, float pz);

t_point	set_pt_color(t_point pt, t_color color);

#endif
