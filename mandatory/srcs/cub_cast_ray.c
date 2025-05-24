#include "mlx.h"
#include "cub.h"
#include "idk.h"
#include "cub_ray.h"

t_cub_ray	*cub_cast_ray(t_cub *cub, float angle, float distance)
{
	t_cub_ray	*result;
	t_point		player;
	t_point		tmp_ray1;
	t_point		tmp_ray2;
	t_point		ray;
	//float		hypo;
	float		screen_dist;
	float		delta_x;
	float		delta_y;
	int			limits;

	result = new_cub_ray_obj();
	screen_dist = 0.0f;
	player = cub->player->camera->pos;
	ray = player;
	delta_x = cos(deg2_rad(angle));
	delta_y = sin(deg2_rad(angle));
	ray.px += delta_x * distance * 100;
	ray.py += delta_y * distance * 100;
	ray.pz = -1.0f;

	limits = check_limits_dda(angle);

	if (limits)
	{
		if (limits == 1)
			tmp_ray1 = dda_calculate_x_right(cub, delta_x, delta_y);
		else if (limits == 2)
			tmp_ray1 = dda_calculate_y_down(cub, delta_x, delta_y);
		else if (limits == 3)
			tmp_ray1 = dda_calculate_x_left(cub, delta_x, delta_y);
		else if (limits == 4)
			tmp_ray1 = dda_calculate_y_up(cub, delta_x, delta_y);
		ray = cmp_dists(player, &tmp_ray1, &ray, NULL);
	}
	else if ((int)angle < 90 && (int)angle > 0)
	{
		tmp_ray1 = dda_calculate_x_right(cub, delta_x, delta_y);
		tmp_ray2 = dda_calculate_y_down(cub, delta_x, delta_y);
		ray = cmp_dists(player, &tmp_ray1, &tmp_ray2, &ray);
	}
	else if ((int)angle > 270 && (int)angle < 360)
	{
		tmp_ray1 = dda_calculate_x_right(cub, delta_x, delta_y);
		tmp_ray2 = dda_calculate_y_up(cub, delta_x, delta_y);
		ray = cmp_dists(player, &tmp_ray1, &tmp_ray2, &ray);
	}
	else if (angle > 90.0f && angle < 180.0f)
	{
		tmp_ray1 = dda_calculate_x_left(cub, delta_x, delta_y);
		tmp_ray2 = dda_calculate_y_down(cub, delta_x, delta_y);
		ray = cmp_dists(player, &tmp_ray1, &tmp_ray2, &ray);
	}
	else if (angle > 180.0f && angle < 270.0f)
	{
		tmp_ray1 = dda_calculate_x_left(cub, delta_x, delta_y);
		tmp_ray2 = dda_calculate_y_up(cub, delta_x, delta_y);
		ray = cmp_dists(player, &tmp_ray1, &tmp_ray2, &ray);
	}
	//hypo = distance_between_points(player, ray);
	result->x = (int)ray.px;
	result->real_x = ray.px;
	result->real_y = ray.py;
	result->y = (int)ray.py;
	result->dist = screen_dist;
	result->deltx = delta_x;
	result->delty = delta_y;
	result->real_dist = distance_between_points(ray, player);

	if (ray.pz > -1.0f)
	{
		result->side = (int)ray.pz;
		result->hit = 1;
	}
	else
	{
		result->hit = 0;
		result->side = (int)ray.pz;
	}
	if (result->dist < distance)
		result->hit = 1;
	return (result);
}
