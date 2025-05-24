/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:33:20 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/17 15:33:20 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include <time.h>

void	k_w(t_cub *cub)
{
	cub->player->camera->pos.px += 1.0 * cub->p_deltas.px * cub->delta_time;
	cub->player->camera->pos.py += 1.0 * cub->p_deltas.py * cub->delta_time;
}

void	k_s(t_cub *cub)
{
	cub->player->camera->pos.px -= 1.0 * cub->p_deltas.px * cub->delta_time;
	cub->player->camera->pos.py -= 1.0 * cub->p_deltas.py * cub->delta_time;
}

void	k_a(t_cub *cub)
{
	cub->player->camera->pos.px += 1.0 * cub->p_deltas.py * cub->delta_time;
	cub->player->camera->pos.py -= 1.0 * cub->p_deltas.px * cub->delta_time;
}

void	k_d(t_cub *cub)
{
	cub->player->camera->pos.px -= 1.0 * cub->p_deltas.py * cub->delta_time;
	cub->player->camera->pos.py += 1.0 * cub->p_deltas.px * cub->delta_time;
}
