/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:15:48 by afelicia          #+#    #+#             */
/*   Updated: 2025/05/25 19:11:49 by acaceres         ###   ########.fr       */
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
		return (free_cub(&cub), 0/*i_g_s_error(cub)*/); //liberar malloc de cub y salir clean 
	if (parsingmap(argv, cub) == 0) //---> 
	{
		return (0);
	}
	if (!open_wall_tex(cub))
	{
		return (0);
	}
	return (1);
}

/*
	ft_constructor
	Allocates the hole struct, use bzero to NULL every element, 
	then initialize every single one of them with custom funtions.
	After bzero every error in funtion have to use the ft_freeGenStruct
	or error handling and return NULL after that
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
