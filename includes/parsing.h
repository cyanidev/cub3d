/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:57:51 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 23:15:39 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "T_Engine.h"
# include "mlx_utils.h"
# include "cub.h"
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_player_pos
{
	double	x;
	double	y;
	char	dir;
	double	plane_x;
	double	plane_y;
	float	angle;
}				t_player_pos;

typedef struct s_map_info
{
	int		fd;
	int		lines;
	char	*path;
	char	**file;
	int		height;
	int		width;
	int		index_end_of_map;
}				t_map_info;

typedef struct s_cubp
{
	t_map_info		map_info;
	char			*north_path;
	char			*south_path;
	char			*east_path;
	char			*west_path;
	int				*floor;
	int				*ceiling;
	unsigned long	x_floor;
	unsigned long	x_ceiling;
	char			**map;
	t_player_pos	player_pos;
}				t_cubp;

int			parsing(t_cubp *cubp, char **argv);
int			parse_map(char *path, t_cubp *cubp);
int			check_file(char *arg);
int			print_msg(char *msg, int ret);
int			ft_isspace(char c);
int			ft_isspace_no_nl(char c);
int			fill_map(t_cubp *cubp, char **file, int i);
int			check_map(t_cubp *cubp, char **map);
void		free_parsing(t_cubp *cubp);
void		free_tab(void **tab);
int			fill_textures(t_cubp *cubp, char *line, int i);
int			fill_color(t_cubp *cubp, char *line, int i);
int			check_dir(char *arg);
int			check_texture(t_cubp *cubp);
int			check_path(char *arg);
void		player_dir(t_cubp *cubp);
void		change_space_to_empty(t_cubp *cubp);
int			map_alloc_height(t_cubp *cubp, char **file, int i);
int			replace_player_with_floor(t_cubp *cubp, char **map);
int			valid_pos(t_cubp *cubp, char **map);
int			check_player(t_cubp *cubp, char **map);
int			ft_isprint_no_ws(int c);
int			parsingmap(char **argv, t_cub *cub);
void		free_textures(t_cubp *cubp);
void		free_floor_n_ceiling(t_cubp *cubp);
int			fill_structure(t_cub *cub, t_cubp *cubp);

#endif
