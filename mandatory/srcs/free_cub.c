/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:51:38 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 23:49:29 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_render.h"

static void	ft_pfree(void **p)
{
	if (p == NULL)
		return ;
	if (*p == NULL)
		return ;
	free(*p);
	*p = NULL;
}

void	free_player(t_player *player)
{
	if (player == NULL)
		return ;
	if (player->camera && player->camera->screen
		&& player->camera->screen->pixels)
		ft_pfree((void **)&player->camera->screen->pixels);
	if (player->camera && player->camera->screen)
		ft_pfree((void **)&player->camera->screen);
	if (player->camera)
		ft_pfree((void **)&player->camera);
	if (player)
		ft_pfree((void **)&player);
}

void	free_cub(t_cub **cub)
{
	t_cub	*tmp;

	tmp = *cub;
	if (tmp == NULL)
		return ;
	if (tmp->mlx && tmp->main_window && tmp->main_window->mlx_win)
		mlx_destroy_window(tmp->mlx, tmp->main_window->mlx_win);
	ft_pfree((void **)&tmp->main_window);
	free_tab((void **)tmp->map);
	free_img(tmp->editor_img, tmp->mlx);
	free_img(tmp->game_img, tmp->mlx);
	free_img(tmp->minimap_img, tmp->mlx);
	free_img(tmp->test_tex, tmp->mlx);
	free_img(tmp->north, tmp->mlx);
	free_img(tmp->south, tmp->mlx);
	free_img(tmp->east, tmp->mlx);
	free_img(tmp->west, tmp->mlx);
	ft_pfree((void **)&tmp->north_path);
	ft_pfree((void **)&tmp->south_path);
	ft_pfree((void **)&tmp->east_path);
	ft_pfree((void **)&tmp->west_path);
	free_player(tmp->player);
	mlx_destroy_display(tmp->mlx);
	ft_pfree((void **)&tmp->mlx);
	ft_pfree((void **)&tmp);
}
