/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input_mapping_obj.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:27 by Andie             #+#    #+#             */
/*   Updated: 2025/05/23 12:38:12 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "cub_ray.h"
#include "engine_obj.h"

void	del_input_mapping_obj(t_input_mapping *obj)
{
	if (obj)
	{
		list_clear(&obj->actions);
		ft_bzero(obj, sizeof(t_input_mapping));
		free(obj);
	}
}

t_input_mapping	*new_input_mapping_obj(void)
{
	t_input_mapping	*result;

	result = malloc(sizeof(t_input_mapping));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_input_mapping));
	result->del = del_input_mapping_obj;
	return (result);
}
*/