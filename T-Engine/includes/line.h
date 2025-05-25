/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:53:59 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:53:59 by acaceres         ###   ########.fr       */
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
