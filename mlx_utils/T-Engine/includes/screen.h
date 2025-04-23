/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:02:49 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/05 02:18:39 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H
# include <stdio.h>
# include "resolution.h"

/*
	Screen struct works like an object
	Is highly recommended to use it with 
	screen custom funtions:
*/
typedef struct s_screen
{
	int				*pixels;
	t_resolution	resolution;
}		t_screen;

t_screen	*new_screen(t_resolution resolution);
void		*free_screen(t_screen *screen);

#endif
