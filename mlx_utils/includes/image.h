/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:22:04 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/11 13:22:07 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "libft.h"


typedef struct s_img{
	char			*path;
	char			*data_addr;
	void			*img;
	int				*pixel_addr;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	t_resolution	resolution;
	float			alpha;
}				t_img;

void	free_img(t_img *img);
void	fill_img(t_img *img, t_color color);
t_img	*init_img(void *mlx, t_resolution res);
t_img	*open_img(void *mlx, char *path);

#endif
