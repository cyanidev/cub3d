/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:37:19 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/24 15:41:59 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include "mlx.h"
# include "cub.h"
# include "idk.h"
# include <time.h>

typedef struct s_input_mapping
{
	t_list			actions;
	void			(*del)();
}				t_input_mapping;

typedef struct s_engine_game_mode
{
	char			*name;
	t_input_mapping	*input_context;
	void			(*engine_game_mode)();
	void			(*del)();
}				t_engine_game_mode;

typedef struct s_engine
{
	t_cub				*cub;
	unsigned int		frame;
	double				delta_time;
	t_engine_game_mode	*actual_game_mode;
	t_list				game_modes;
	t_list				obj;
	void				(*del)();
}				t_engine;

#endif
