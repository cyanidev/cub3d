/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:51:38 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 19:10:38 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_render.h"

static void	ft_pfree(void **p)
{
	if (*p == NULL)
		return ;
	free(*p);
	*p = NULL;
}

void	free_cub_img(t_img *img)
{
	if (img == NULL)
		return ;
	if (img->path != NULL)
		printf("img->path: %s\n", img->path);
}

void	free_player(t_player *player)
{
	if (player == NULL)
		return ;
	//ft_pfree((void **)&player->camera->screen->pixels);
	//ft_pfree((void **)&player->camera->screen);
	//ft_pfree((void **)&player);
}

void	free_cub(t_cub **cub)
{
	t_cub	*tmp;

	tmp = *cub;
	if (tmp == NULL)
		return ;
	if (tmp->mlx && tmp->main_window && tmp->main_window->mlx_win)
		mlx_destroy_window(tmp->mlx, tmp->main_window->mlx_win);
	ft_pfree((void **)&tmp->editor_img);
	ft_pfree((void **)&tmp->game_img);
	ft_pfree((void **)&tmp->minimap_img);
	ft_pfree((void **)&tmp->test_tex);
	free_player(tmp->player);
	free_cub_img(tmp->north);
	mlx_destroy_display(tmp->mlx);
	ft_pfree((void **)&tmp->mlx);
	ft_pfree((void **)&tmp);
}
