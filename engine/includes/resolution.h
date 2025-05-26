/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:54:32 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/26 16:47:23 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_H
# define RESOLUTION_H

typedef struct s_resolution
{
	unsigned int	width;
	unsigned int	height;
}		t_resolution;

// set resolution by hand
t_resolution	resolution(unsigned int width, unsigned int height);

// set the resolution by aspect ratio
t_resolution	set_res_by_a_r(char *aspect_ratio);

#endif
