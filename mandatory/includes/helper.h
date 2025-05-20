/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:16:43 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/20 16:46:28 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <stddef.h>

typedef struct s_helper
{
	int		x;
	int		y;
	float	x_prop;
	float	y_prop;
	float	aspect_ratio;
}		t_helper;

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


#endif
