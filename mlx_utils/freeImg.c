/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeImg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:00:09 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 23:00:09 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	free_img(t_img *img, void *mlx)
{
	if (!img)
		return ;
	if (img->path)
		free(img->path);
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	ft_bzero(img, sizeof(t_img));
	free(img);
}
