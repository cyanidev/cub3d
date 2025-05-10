/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:01:19 by afelicia          #+#    #+#             */
/*   Updated: 2024/10/13 22:01:22 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include <time.h>

t_hooks	hooks(int (*option1)(), int (*option2)())
{
	t_hooks	result;

	result.option1 = option1;
	result.option2 = option2;
	return (result);
}

t_win_hooks	win_hooks(t_hooks mouse, t_hooks key, t_hooks focus)
{
	t_win_hooks	result;

	result.mouse = mouse;
	result.key = key;
	result.focus = focus;
	return (result);
}

t_win	*new_window(void *mlx, t_resolution res, char *title)
{
	t_win				*result;
	static unsigned int	id = 0;

	result = malloc(sizeof(t_win));
	if (!result)
		return (NULL);
	result->mlx_win = mlx_new_window(mlx, res.width, res.height, title);
	if (!result->mlx_win)
	{
		free(result);
		return (NULL);
	}
	result->res = res;
	result->id = id++;
	return (result);
}

void	start_hooks_in_window(t_win *win, t_win_hooks win_hooks, void *data)
{
	if (!win)
		return ;
	if (win_hooks.mouse.option1)
		mlx_hook(win->mlx_win, 4, (1L << 2), win_hooks.mouse.option1, data);
	if (win_hooks.mouse.option2)
		mlx_hook(win->mlx_win, 5, (1L << 3), win_hooks.mouse.option2, data);
	if (win_hooks.key.option1)
		mlx_hook(win->mlx_win, 2, (1L << 0), win_hooks.key.option1, data);
	if (win_hooks.focus.option1)
		mlx_hook(win->mlx_win, 9, (1L << 21), win_hooks.focus.option1, data);
	if (win_hooks.focus.option2)
		mlx_hook(win->mlx_win, 10, (1L << 21), win_hooks.focus.option2, data);
}
