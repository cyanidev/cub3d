/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:16:43 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/22 18:50:00 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <stddef.h>
# include "cub_render.h"
# include "cub.h"

typedef struct s_intersec
{
	float	div;
	float	x;
	float	y;
}		t_intersec;

typedef struct s_helper
{
	int		x;
	int		y;
	float	x_prop;
	float	y_prop;
	float	aspect_ratio;
}		t_helper;
/*
typedef struct s_rcast
{
	size_t	number_of_rays;
	size_t	iterator;
	float	start_angle;
	float	multiplier;
	float	max_dist;
}		t_rcast;
*/
/*
typedef struct s_dwall
{
	int		wall_height;
	float	dist;
	float	tmp2;
	float	res_height;
	double	last_time;
}		t_dwall;
*/

typedef struct s_drwall
{
	int		wall_top;
	int		min_top;
	int		wall_bottom;
	int		y;
	int		real_pos;
	int		mirror_y;
	int		mirror_helper;
	float	color_mix_lerp;
	float	real_pos_x;
	float	res_height;
}		t_drwall;

typedef struct s_rcast
{
	size_t	number_of_rays;
	size_t	iterator;
	float	start_angle;
	float	multiplier;
	float	max_dist;
}		t_rcast;

typedef struct s_dwall
{
	int		wall_height;
	float	dist;
	float	tmp2;
	float	res_height;
	double	last_time;
}		t_dwall;

typedef struct s_rwall
{
	t_cub		*cub;
	t_cub_ray	*ray;
	t_color		tmp_color;
	float		wall_n;
	float		wall_height;
}		t_rwall;

#endif
