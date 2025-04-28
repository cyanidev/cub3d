/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:56:39 by andie             #+#    #+#             */
/*   Updated: 2024/08/24 23:01:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

static void	north_south(t_player_pos *player_pos)
{
	if (player_pos->dir == 'S')
	{
		player_pos->angle = 90;
	}
	else if (player_pos->dir == 'N')
	{
		player_pos->angle = 270;
	}
	else
		return ;
}

static void	east_west(t_player_pos *player_pos)
{
	if (player_pos->dir == 'W')
	{
		player_pos->angle = 180;
	}
	else if (player_pos->dir == 'E')
	{
		player_pos->angle = 0;
	}
	else
		return ;
}

void	player_dir(t_cubp *cubp)
{
	north_south(&cubp->player_pos);
	east_west(&cubp->player_pos);
}
