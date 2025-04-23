/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cub_ray_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:42:18 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 22:01:23 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "cub_ray.h"

t_cub_ray	*new_cub_ray_obj(void)
{
	t_cub_ray	*result;

	result = malloc(sizeof(t_cub_ray));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(t_cub_ray));
	result->del = del_cub_ray_obj;
	return (result);
}
