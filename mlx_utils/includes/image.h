/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:58:53 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 23:56:42 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "libft.h"

typedef struct s_img
{
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

void	free_img(t_img *img, void *mlx);
void	fill_img(t_img *img, t_color color);
t_img	*init_img(void *mlx, t_resolution res);
t_img	*open_img(void *mlx, char *path);
int		mlx_main(void);

#endif
