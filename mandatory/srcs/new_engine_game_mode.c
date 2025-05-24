/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_engine_game_mode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:23 by Andie             #+#    #+#             */
/*   Updated: 2025/05/22 19:58:48 by acaceres         ###   ########.fr       */
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
	return (NULL);
}

t_engine_game_mode	*new_engine_game_mode(char *name)
{
	t_engine_game_mode	*result;

	result = malloc(sizeof(t_engine_game_mode));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_engine_game_mode));
	result->del = (void *)del_engine_game_mode;
	if (!name)
	{
		result->del(result);
		return (NULL);
	}
	return (result);
}
