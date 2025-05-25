/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:57:38 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:57:39 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

static int	while_condition(t_cubp *cubp, char **map, int i, int j)
{
	while (ft_isspace(map[i][j]))
		j++;
	if (ft_isprint_no_ws(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint_no_ws(map[i][j + 1]))
		{
			if (fill_textures(cubp, map[i], j) == 0)
				return (print_msg("Error in textures.", 0));
			return (3);
		}
		else
		{
			if (fill_color(cubp, map[i], j) == 0)
				return (0);
			return (3);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (fill_map(cubp, map, i) == 0)
			return (print_msg("Error in map.", 0));
		return (1);
	}
	return (2);
}

int	fill_info(t_cubp *cubp, char **map)
{
	int	i;
	int	j;
	int	stop;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			stop = while_condition(cubp, map, i, j);
			if (stop == 3)
				break ;
			else if (stop == 1)
				return (1);
			else if (stop == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(t_cubp *cubp, char **argv)
{
	if (check_file(argv[1]) == 0)
		return (print_msg("Invalid file", 0));//--hasta aqui retorna 0 y se libera cub, aqui cubp no tiene malloc
	if (parse_map(argv[1], cubp) == 0)//ok
		return (0);
	if (fill_info(cubp, cubp->map_info.file) == 0)//ok
		return (0);
	if (check_map(cubp, cubp->map) == 0)//ok
		return (0);
	if (check_texture(cubp) == 0)//ok
		return (0);
	player_dir(cubp);
	return (1);
}
