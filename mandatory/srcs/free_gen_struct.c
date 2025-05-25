/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gen_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:08 by Andie             #+#    #+#             */
/*   Updated: 2025/05/25 20:36:05 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include "cub_ray.h"

void	free_gen_struct(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->mlx)
		free(cub->mlx);
	if (cub->north_path)
		free(cub->north_path);
	if (cub->south_path)
		free(cub->south_path);
	if (cub->east_path)
		free(cub->east_path);
	if (cub->west_path)
		free(cub->west_path);
	if (cub->north)
		free_img(cub->north, cub->mlx);
	if (cub->south)
		free_img(cub->south, cub->mlx);
	if (cub->east)
		free_img(cub->east, cub->mlx);
	if (cub->west)
		free_img(cub->west, cub->mlx);
	ft_bzero(cub, sizeof(t_cub));
	free(cub);
}
