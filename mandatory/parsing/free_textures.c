/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:12:17 by afelicia          #+#    #+#             */
/*   Updated: 2025/05/24 18:12:20 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	free_textures(t_cubp *cubp)
{
	if (cubp->north_path)
	{
		free(cubp->north_path);
		cubp->north_path = NULL;
	}
	if (cubp->south_path)
	{
		free(cubp->south_path);
		cubp->south_path = NULL;
	}
	if (cubp->west_path)
	{
		free(cubp->west_path);
		cubp->west_path = NULL;
	}
	if (cubp->east_path)
	{
		free(cubp->east_path);
		cubp->east_path = NULL;
	}
}

void	free_floor_n_ceiling(t_cubp *cubp)
{
	if (cubp->floor)
	{
		free(cubp->floor);
		cubp->floor = NULL;
	}
	if (cubp->ceiling)
	{
		free(cubp->ceiling);
		cubp->ceiling = NULL;
	}
}
