/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:53:40 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:53:40 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "point.h"
# include "screen.h"

typedef struct s_camera
{
	t_point			pos;
	float			angle;
	float			fov;
	t_screen		*screen;
}		t_camera;

t_camera	*new_camera(t_point pos, float angle, float fov, t_screen *screen);
void		free_camera(t_camera *cam);

#endif
