/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cub_ray_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:39:22 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 21:13:06 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include "cub_ray.h"

void	del_cub_ray_obj(t_cub_ray *obj)
{
	if (obj)
	{
		ft_bzero(obj, sizeof(t_cub_ray));
		free(obj);
	}
}
