/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:59:17 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:59:18 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRENSENHAM_H
# define BRENSENHAM_H
# include "libft.h"
# include "T_Engine.h"
# include <math.h>

typedef struct s_bb{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	t_line	line;
}				t_bb;

void	draw_line(t_point f, t_point s, t_img *map_display);

#endif
