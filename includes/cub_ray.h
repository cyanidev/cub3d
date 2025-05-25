/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ray.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:37:04 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 22:39:59 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RAY_H
# define CUB_RAY_H
# include "libft.h"
# include "T_Engine.h"
# include "mlx_utils.h"
# include "cub.h"

typedef struct s_cub_ray
{
	int		hit;
	int		side;
	int		x;
	float	real_x;
	int		y;
	float	real_y;
	float	dist;
	float	real_dist;
	float	deltx;
	float	delty;
	int		(*del)();
}				t_cub_ray;

typedef struct s_cubcastray
{
	t_cub_ray	*result;
	t_point		player;
	t_point		tmp_ray1;
	t_point		tmp_ray2;
	t_point		ray;
	float		hypo;
	float		screen_dist;
	float		delta_x;
	float		delta_y;
	int			limits;
}		t_ccr; // type cube cast ray

void	ray_angle_zero_to_nineth(t_cub *cub, t_ccr *ccr);
void	ray_angle_two_seven_three_sixth(t_cub *cub, t_ccr *ccr);
void	ray_angle_nineth_onehundred(t_cub *cub, t_ccr *ccr);
void	ray_angle_onehundred_twohundred_seventh(t_cub *cub, t_ccr *ccr);

#endif
