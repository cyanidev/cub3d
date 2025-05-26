/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:53:52 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/26 16:40:23 by acaceres         ###   ########.fr       */
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
