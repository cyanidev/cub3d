/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:10:36 by samusanc          #+#    #+#             */
/*   Updated: 2025/05/25 22:51:48 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H
# include "point.h"

typedef struct s_line
{
	t_point	a;
	t_point	b;
}		t_line;

t_line	line(t_point a, t_point b);

#endif
