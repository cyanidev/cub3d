/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_engine_game_mode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:23 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 22:01:50 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "cub_ray.h"
#include "engine_obj.h"

void	*del_engine_game_mode(t_engine_game_mode *obj)
{
	if (obj)
	{
		free(obj->name);
		obj->input_context->del(obj->input_context);
		ft_bzero(obj, sizeof(t_engine_game_mode));
		free(obj);
	}
}

t_engine_game_mode	*new_engine_game_mode(char *name)
{
	t_engine_game_mode	*result;
	char				*name_tmp;

	result = malloc(sizeof(t_engine_game_mode));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_engine_game_mode));
	result->del = del_engine_game_mode;
	name_tmp = ft_strdup(name);
	if (!name)
	{
		result->del(result);
		return (NULL);
	}
	return (result);
}
