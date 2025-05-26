/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:56:10 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/26 16:47:06 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolution.h"

t_resolution	resolution(unsigned int width, unsigned int height)
{
	t_resolution	result;

	result.width = width;
	result.height = height;
	return (result);
}
