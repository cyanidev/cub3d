/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeImg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:56:01 by samusanc          #+#    #+#             */
/*   Updated: 2025/05/25 20:54:21 by acaceres         ###   ########.fr       */
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
