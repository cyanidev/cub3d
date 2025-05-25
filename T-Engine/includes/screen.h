/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:54:42 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:54:43 by acaceres         ###   ########.fr       */
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

#endif
