/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:54:16 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:54:16 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "camera.h"

/*
	Player
		camera: the camera of the player, aka t_cam
		start: Unity-like or Unreal-like funtion,
		It is executed when the object is born.
		update: Unity-like funtion, it is called each frame.
*/
typedef struct s_player
{
	t_camera	*camera;
	int			(*start)(struct s_player, void *);
	int			(*update)(struct s_player, void *);
}		t_player;

// Player Constructor
t_player	*new_player(t_camera *camera);
void		free_player(t_player *player);

#endif
