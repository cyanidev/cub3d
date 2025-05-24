/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:38:33 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:44:27 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

int	check_wall_in_map(int x, int y, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x < 0 || y < 0)
		return (0);
	while (map[i])
		i++;
	while (map[0][j])
		j++;
	if (y >= i || x >= j)
		return (0);
	if (map[y][x] == '1')
		return (1);
	return (0);
}
