/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:45:22 by afelicia          #+#    #+#             */
/*   Updated: 2025/05/25 23:32:37 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

static ssize_t	arr_len(char **arr)
{
	ssize_t	i;

	i = 0;
	if (arr == NULL)
		return (-1);
	while (arr[i] != NULL)
		i++;
	return (i);
}

static char	**copy_arr(char **arr)
{
	char	**narr;
	ssize_t	len;
	int		i;

	i = 0;
	if (arr == NULL)
		return (NULL);
	len = arr_len(arr);
	if (len == -1)
		return (NULL);
	narr = (char **)malloc(sizeof(char *) * (len + 1));
	if (narr == NULL)
		return (NULL);
	while (arr[i] != NULL)
	{
		narr[i] = ft_strdup(arr[i]);
		if (narr[i] == NULL)
			return (free_tab((void **)(narr)), NULL);
		i++;
	}
	narr[i] = NULL;
	return (narr);
}

int	fill_structure(t_cub *cub, t_cubp *cubp)
{
	cub->north_path = ft_strdup(cubp->north_path);
	if (cub->north_path == NULL)
		return (0);
	cub->south_path = ft_strdup(cubp->south_path);
	if (cub->south_path == NULL)
		return (0);
	cub->east_path = ft_strdup(cubp->east_path);
	if (cub->east_path == NULL)
		return (0);
	cub->west_path = ft_strdup(cubp->west_path);
	if (cub->west_path == NULL)
		return (0);
	cub->map = copy_arr(cubp->map);
	if (cub->map == NULL)
		return (0);
	cub->floor = color_from_rgb(cubp->floor[0],
			cubp->floor[1], cubp->floor[2]);
	cub->ceiling = color_from_rgb(cubp->ceiling[0],
			cubp->ceiling[1], cubp->ceiling[2]);
	cub->parsing_px = cubp->player_pos.plane_x;
	cub->parsing_py = cubp->player_pos.plane_y;
	cub->player_angle = cubp->player_pos.angle;
	return (1);
}
