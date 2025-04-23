/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_action_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:13 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 22:00:50 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "cub_ray.h"
#include "engine_obj.h"

void	del_action_obj(t_action *obj)
{
	if (obj)
	{
		ft_bzero(obj, sizeof(t_action));
		free(obj);
	}
}

t_action	*new_action_obj(t_event event)
{
	t_action	*result;

	result = malloc(sizeof(t_action));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_action));
	result->del = del_action_obj;
	result->triggered = NULL;
	result->ongoing = NULL;
	return (result);
}
