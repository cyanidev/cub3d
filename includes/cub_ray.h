#ifndef CUB_RAY_H
# define CUB_RAY_H
# include "libft.h"
# include "T_Engine.h"
# include "mlx_utils.h"
# include "engine.h"
# include "cub.h"

typedef	struct s_cub_ray
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

# endif