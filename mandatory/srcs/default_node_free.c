/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_node_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:39:16 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 21:13:02 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"
#include "cub_ray.h"
#include "engine_obj.h"

void	*default_node_free(void *ptr)
{
	free(ptr);
	return (NULL);
}
