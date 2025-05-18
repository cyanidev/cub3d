#ifndef IDK_H
# define IDK_H
# include "libft.h"
# include "T_Engine.h"
# include "mlx_utils.h"
# include "engine.h"
# include "cub.h"
# include "cub_ray.h"

#define EPS 1e-4

extern clock_t	g_start_t;

// player angle struct
typedef struct s_angle
{
	t_point	*fov1;
	t_point	*fov2;
	float	angle;
}		t_angle;

typedef enum e_event_type
{
	mouse,
	keyboard,
	focus
}			t_event_type;

typedef struct s_event
{
	t_event_type	type;
	int				id;
	int				triggered;
	int				ongoing;
}				t_event;

typedef	struct s_action
{
	t_event event;
	void	(*triggered)();
	void	(*ongoing)();
	void	(*del)();
}				t_action;

typedef struct s_hline
{
	int	x0;
	int	y0;
	int	x1;
}		t_hline;

typedef struct s_dcircle
{
	int	cx;
	int	cy;
	int	error;
	int	x;
	int	y;
	int	lasty;
	t_img	*img;
	t_color	color;
}		t_dcircle;


//ERRORS
int	i_g_s_error(t_cub *cub);

//INIT
int	open_wall_tex(t_cub *cub);
//int	init_gen_struct(t_cub *cub, char *map_path, char **argv);
t_cub	*ft_constructor(char *map_path, char **argv);
t_img	*open_img(void *mlx, char *path);


//HOOKS
t_hooks	hooks(int (*option1)(), int (*option2)());
t_win_hooks	win_hooks(t_hooks mouse, t_hooks key, t_hooks focus);
t_win	*new_window(void *mlx, t_resolution res, char *title);
void	start_hooks_in_window (t_win *win, t_win_hooks win_hooks, void *data);

//DRAW STUFF
void	draw_circle(int radius, t_img *img, t_point center);
int	draw_player(t_cub *cub, t_map_editor map_editor, t_color col, t_img *img);
void	draw_sky_and_ground(t_cub *cub, int wall_top, size_t wall_n, int wall_bottom);
int	draw_grid(t_map_editor editor, t_img *img, t_color color);
int	draw_map_walls(t_cub *cub, t_map_editor editor, t_img *img);
int	draw_square(size_t length, t_img *img, t_point start);
void draw_wall(float max_dist, int wall_height, t_cub *cub, size_t wall_n, t_cub_ray *ray, float angle);


// REMAP
t_point	remap_point(t_point pt, int zoom, t_point center, t_resolution res);
t_point	undo_remap_point(t_point pt, int zoom, t_point center, t_resolution res);

//MOUSE EVENTS
int	mouse_press(int key, int x, int y, void *param);
int	mouse_release(int key, int x, int y, void *param);
int	focus_out(void *param);
int	focus_in(void *param);
t_point	mouse_pos_relative(t_cub *cub, t_win *win);

//KEY EVENTS
int	key_press(int key, void *param);
int	key_press_game(int key, t_cub *cub);

// KEY EVENTS CALCS
int	key_press_editor(int key, t_cub *cub);
void	k_e(t_cub *cub);
void	k_q(t_cub *cub);
void	k_0(t_cub *cub);
void	k_9(t_cub *cub);

// KEY EVENTS UTILS
void	k_w(t_cub *cub);
void	k_s(t_cub *cub);
void	k_a(t_cub *cub);
void	k_d(t_cub *cub);

//FRAME UPDATE
int	frame(void *p_cub);

//notsure
t_resolution	resolution(unsigned int width, unsigned int height);
t_img	*init_img(void *mlx, t_resolution res);

//PLAYER
t_player *new_player(t_camera *camera);

//MATH
int calculate_deltas(t_player *player, t_point *deltas, t_point *fov1, t_point *fov2);
//int	update_player_angle(t_player *player, t_point *deltas, t_point *fov1, t_point *fov2, float angle);
int	update_player_angle(t_player *player, t_point *deltas, t_angle *angle);

int	update_player_angle_from_angle(t_cub *cub, float angle);//prolynot
float	deg2_rad(float angle);
float	get_dist_delt(float delta_y, float y, float start_y);
int	dda_check_map(t_cub *cub, t_point pt);
t_point	dda_calculate_x_right(t_cub *cub, float delta_x, float delta_y);
t_point	dda_calculate_x_left(t_cub *cub, float delta_x, float delta_y);
t_point	dda_calculate_y_down(t_cub *cub, float delta_x, float delta_y);
t_point	dda_calculate_y_up(t_cub *cub, float delta_x, float delta_y);
float	distance_between_points(t_point a, t_point b);
t_cub_ray	*new_cub_ray_obj();
void	del_cub_ray_obj(t_cub_ray *obj);
int	check_limits_dda(float angle);
t_point	cmp_dists(t_point start, t_point *dist1, t_point *dist2, t_point *dist3);

//COLOR
t_color color(t_colors name);

//position
float	get_real_pos_x(float x, float y, int side);

//pixel
int	get_pixel_img(t_img *img, int x, int y);
int	clean_pixels(t_img *img);
int	ray_casting(t_cub *cub, t_map_editor minimap);
int	game_mode(t_cub *cub);

//free
void	free_gen_struct(t_cub *cub);

int editor_mode(t_cub *cub);
t_map_editor	map_editor();

int	render_normal_mode(t_cub *cub);

float	fix_angle(float angle);

t_cub_ray	*cub_cast_ray(t_cub *cub, float angle, float distance, t_map_editor minimap);


# endif
