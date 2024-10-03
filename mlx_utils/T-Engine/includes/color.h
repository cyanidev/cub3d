/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:16:21 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/14 15:17:47 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef enum e_colors
{
	black,
	BLACK,
	white,
	WHITE,
	red,
	RED,
	green,
	GREEN,
	blue,
	BLUE
}			t_colors;

/*
  The alpha value goes from 0 to 1 
  where 0 is completely transparent and 1 not transparent at all.
*/
typedef struct s_color
{
	unsigned int		hex;
	int					r;
	int					g;
	int					b;
	float				alpha;
}		t_color;

t_color	color(t_colors name);
t_color	color_from_rgb(int red, int green, int blue);
t_color	color_from_rgba(int red, int green, int blue, float alpha);
t_color	color_from_hex(int color);
t_color	color_mix(t_color a, t_color b, float lerp);

#endif
