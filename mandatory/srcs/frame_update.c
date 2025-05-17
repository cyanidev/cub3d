/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:00 by Andie             #+#    #+#             */
/*   Updated: 2025/05/17 13:48:56 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "engine.h"
#include <time.h>

int	frame(void *p_cub)
{
	clock_t	g_start_t;
	t_cub	*cub;

	g_start_t = clock();
	cub = (t_cub *)p_cub;
	cub->frame += 1;
	cub->delta_time = 0.016f;
	if (cub->game_mode == GAME)
		game_mode(cub);
	else if (cub->game_mode == EDITOR)
		editor_mode(cub);
	return (0);
}
