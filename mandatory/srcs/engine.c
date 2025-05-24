/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:40:49 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 21:24:20 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include "engine.h"
#include <time.h>

void	del_engine_obj(t_engine *obj)
{
	if (obj)
	{
		obj->cub->del(obj->cub);
		list_clear(&obj->game_modes);
		list_clear(&obj->obj);
		ft_bzero(obj, sizeof(t_engine));
		free(obj);
	}
}

t_engine	*new_engine_obj(void)
{
	t_engine	*result;

	result = malloc(sizeof(t_engine));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_engine));
	result->del = del_engine_obj;
	return (result);
}
