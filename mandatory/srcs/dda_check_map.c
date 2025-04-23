/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:39:12 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 21:12:49 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

int	dda_check_map(t_cub *cub, t_point pt)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	x = (int)pt.px;
	y = (int)pt.py;
	if (x < 0 || y < 0)
		return (-1);
	while (cub->map[i])
		i++;
	i--;
	while (cub->map[0][j])
		j++;
	j--;
	if (y > i || x > j)
		return (-1);
	if (cub->map[y][x] == '1')
		return (1);
	return (0);
}
