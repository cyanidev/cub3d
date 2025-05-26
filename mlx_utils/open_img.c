/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:59:59 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 23:55:17 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static t_img	*free_open_img(t_img *img, void *mlx)
{
	free_img(img, mlx);
	return (NULL);
}

static t_img	*open_img_utils(t_img *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path,
			(int *)&img->resolution.width, (int *)&img->resolution.height);
	if (!img->img)
		return (free_open_img(img, mlx));
	img->data_addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_size), &(img->endian));
	if (!img->data_addr)
		return (free_open_img(img, mlx));
	img->pixel_addr = (int *)mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_size), &(img->endian));
	if (!img->pixel_addr)
		return (free_open_img(img, mlx));
	return (img);
}

t_img	*open_img(void *mlx, char *path)
{
	t_img	*img;

	if (!path)
		return (NULL);
	img = malloc(sizeof(t_img) * 1);
	if (!img)
		return (NULL);
	ft_bzero(img, sizeof(t_img));
	if (!open_img_utils(img, mlx, path))
		return (NULL);
	return (img);
}
