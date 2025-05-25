/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:36:39 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 17:32:36 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdlib.h>
# include "libft.h"
# include "T_Engine.h"
# include "mlx_utils.h"
# include <X11/keysym.h>

//typedef structs_bsp	t_bsp;

typedef struct s_map_editor
{
	t_point			screen_center;
	int				screen_zoom;
}			t_map_editor;

typedef enum e_game_mode
{
	GAME,
	EDITOR
}				t_game_mode;

typedef struct s_hooks
{
	int	(*option1)();
	int	(*option2)();
}				t_hooks;

typedef struct s_win_hooks
{
	t_hooks	mouse;
	t_hooks	key;
	t_hooks	focus;
}				t_win_hooks;

typedef struct s_win
{
	void			*mlx_win;
	t_resolution	res;
	unsigned int	id;
}				t_win;

typedef struct s_triple_buff_img
{
	t_img			*render;
	t_img			*buffer_a;
	t_img			*buffer_b;
}				t_triple_buff_img;

typedef struct s_cub
{
	t_map_editor		map_editor;

	void				*mlx;
	t_win				*main_window;
	unsigned int		frame;
	double				delta_time;
	t_game_mode			game_mode;
	int					focus;
	int					mouse_press;
	t_point				last_mouse_grab;
	t_img				*editor_img;
	t_img				*game_img;
	t_img				*minimap_img;
	t_img				*test_tex;
	float				parsing_px;
	float				parsing_py;
	float				player_angle;
	float				ambient_occlusion;
	float				max_dist;
	float				wall_height;
	float				near_plane;
	float				height_multiplier;
	char				*north_path;
	char				*south_path;
	char				*east_path;
	char				*west_path;
	t_color				floor;
	t_color				ceiling;
	char				**map;
	t_player			*player;
	t_point				p_deltas;
	t_point				fov1_deltas;
	t_point				fov2_deltas;
	t_point				fov1_screen;
	t_point				fov2_screen;
	t_img				*north;
	t_img				*south;
	t_img				*east;
	t_img				*west;
	void				(*del)();
}					t_cub;

t_map_editor	map_editor(void);
t_resolution	resolution(unsigned int width, unsigned int height);

#endif
