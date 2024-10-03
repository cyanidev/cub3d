/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:16:55 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/07 13:19:08 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	line(t_point a, t_point b)
{
	t_line	result;

	result.a = a;
	result.b = b;
	return (result);
}
