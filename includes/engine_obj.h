/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_obj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:37:35 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/24 15:42:44 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_OBJ_H
# define ENGINE_OBJ_H
# include "libft.h"
# include "T_Engine.h"
# include "mlx_utils.h"
# include "engine.h"
# include "cub.h"

typedef struct s_engine_obj	t_engine_obj;

typedef struct t_transform
{
	char			*name;
	void			*parent;
	t_point			position;
	t_point			rotation;
	t_list			components;
	t_engine_obj	*(*get_component)();
}				t_transform;

typedef struct s_engine_obj
{
	void		*engine;
	void		*parent;
	t_transform	transform;
	int			(*start)();
	int			(*update)();
	int			(*on_exit)();
	void		(*del)();
}				t_engine_obj;

#endif
