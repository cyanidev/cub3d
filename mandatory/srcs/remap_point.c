/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remap_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:43:13 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 19:43:13 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "idk.h"

t_point	remap_point(t_point pt, int zoom, t_point center, t_resolution res)
{
	t_resolution	half;

	half = resolution(res.width / 2, res.height / 2);
	pt.px *= zoom;
	pt.py *= zoom;
	pt.px += half.width - center.px;
	pt.py += half.height - center.py;
	pt.px = (int)pt.px;
	pt.py = (int)pt.py;
	return (pt);
}

t_point	undo_remap_point(t_point pt, int zoom, t_point center, t_resolution res)
{
	t_resolution	half;

	half = resolution(res.width / 2, res.height / 2);
	pt.px -= half.width - center.px;
	pt.py -= half.height - center.py;
	pt.px = pt.px / zoom;
	pt.py = pt.py / zoom;
	return (pt);
}
