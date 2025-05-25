/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:16:55 by samusanc          #+#    #+#             */
/*   Updated: 2025/05/25 22:47:17 by acaceres         ###   ########.fr       */
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
