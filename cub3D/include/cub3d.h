/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:04:09 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/07 14:53:28 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>

# define W_WIDTH 1920
# define W_HEIGHT 1080

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef struct s_image
{
	char	*path;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				color;
	bool			defined;
}	t_color;

typedef struct s_wall
{
	t_image	no_texture;
	t_image	so_texture;
	t_image	we_texture;
	t_image	ea_texture;
}	t_wall;

typedef struct s_map
{
	char				*path;
	int					fd;
	char				**lines;
	char				**map;
	char				**tmp_map;
	enum e_tile_type	**tiles;
	int					height;
	t_wall				wall;
	t_color				floor_color;
	t_color				ceiling_color;
	int					tile_size;
}						t_map;

typedef struct s_player
{
	double				x;
	double				y;
	enum e_direction	direction;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				move_speed;
	double				rot_speed;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_texture
{
	double	pos;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_texture;

typedef struct s_ray
{
	double		camera_x;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		ray_dir_x;
	double		ray_dir_y;
	double		wall_x;
	double		step;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			floor;
	int			ceiling;
	int			draw_start;
	int			draw_end;
	t_texture	texture;
	t_texture	current_texture;
}			t_ray;

typedef struct s_game
{
	t_image		img;
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_keys		keys;
}	t_game;

void				game_init(t_game *game, char *path);
void				file_check(t_game *game);
void				map_init(t_game *game);
void				init_mlx(t_game *game);
int					get_infos(t_game *game);
int					set_color(t_color *color, char *line);
int					set_texture(t_game *game, t_image *texture, char *path);
void				check_map(t_game *game);
int					ft_pathfinder(char **map, int map_height, int x, int y);
int					game_loop(t_game *game);
void				player_movement(t_game *game);
void				player_rotation(t_game *game);
char				*ft_itoa(int n);
enum e_direction	get_direction(char c);
int					is_valid_map_char(char c);
char				**dublicate_map(t_game *game);
void				free_map(char **map);
void				free_split(char **split);
int					arr_len(char **arr);
int					get_longest_line(char **map);
void				check_is_digit(char **split);
void				get_map_height(t_game *game);
void				get_lines(t_game *game);
void				calc_ray_pos_dir(t_game *game, t_ray *ray, int x);
void				calc_ray_delta_dist(t_ray *ray);
void				calc_ray_step_side_dist(t_game *game, t_ray *ray);
void				perform_dda(t_game *game, t_ray *ray);
void				calc_texture_width_height(t_game *game, t_ray *ray);
void				calc_perp_wall_dist(t_ray *ray);
void				calc_start_end_draw(t_ray *ray);
void				calc_texture(t_game *game, t_ray *ray);
void				draw_line(t_game *game, int x, t_ray *ray);
int					key_press(int key_code, void *game);
int					key_release(int key_code, void *game);
int					exit_game(void *game);

#endif