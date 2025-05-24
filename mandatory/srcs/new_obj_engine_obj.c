/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_obj_engine_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:32 by Andie             #+#    #+#             */
/*   Updated: 2025/05/23 12:14:14 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "cub_ray.h"
#include "engine_obj.h"

t_engine_obj	*get_component(t_engine_obj *parent, char *name)
{
	//srry implement latter or maybe never :p
	return (NULL);
}

t_transform	transform(void)
{
	t_transform	result;

	ft_bzero(&result, sizeof(t_transform));
	result.get_component = get_component;
	return (result);
}

void			del_obj_engine_obj(t_engine_obj *obj)
{
	if (obj)
		list_clear(&obj->transform.components);
	free(obj);
	return ;
}

t_engine_obj	*new_obj_engine_obj(void *engine)
{
	t_engine_obj	*result;

	result = malloc(sizeof(t_engine_obj));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_engine_obj));

	result->engine = engine;
	result->transform = transform();
	result->transform.parent = engine;
	result->del = del_obj_engine_obj;
	return (result);
}

t_node	*add_component(t_engine_obj *obj)
{
	return (node(obj, obj->del));
}*/
