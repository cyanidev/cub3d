/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:15:48 by afelicia          #+#    #+#             */
/*   Updated: 2025/05/26 17:46:19 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include "parsing.h"
#include <time.h>

int	open_wall_tex(t_cub *cub)
{
	cub->north = open_img(cub->mlx, cub->north_path);
	if (!cub->north)
		return (0);
	cub->south = open_img(cub->mlx, cub->south_path);
	if (!cub->south)
		return (0);
	cub->east = open_img(cub->mlx, cub->west_path);
	if (!cub->east)
		return (0);
	cub->west = open_img(cub->mlx, cub->east_path);
	if (!cub->west)
		return (0);
	return (1);
}

int	init_gen_struct(t_cub *cub, char **argv)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (free_cub(&cub), 0);
	if (parsingmap(argv, cub) == 0)
		return (0);
	if (!open_wall_tex(cub))
		return (0);
	return (1);
}

/*
	ft_constructor
	Allocates the hole struct, use bzero to NULL every element, 
	then initialize every single one of them with custom funtions.
*/
int	ft_constructor(char **argv, t_cub **result)
{
	*result = malloc(sizeof(t_cub));
	if (!*result)
		return (0);
	ft_bzero(*result, sizeof(t_cub));
	if (!init_gen_struct(*result, argv))
		return (0);
	return (1);
}
