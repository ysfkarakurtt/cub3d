/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:36:53 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/31 13:36:55 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdbool.h>
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define WIDTH 800
#define HEIGHT 600
#define TEXWIDTH 64
#define TEXHEIGHT 64
#define KEY_EXIT 65307
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_RIGHT 65363
#define KEY_LEFT 65361
#define KEY_ESC 65307

typedef struct s_image
{
	void *image;
	int *addr;
	int number;
} t_image;

typedef struct s_flags
{
	int north_flag;
	int west_flag;
	int east_flag;
	int south_flag;
	int c_flag;
	int f_flag;
	int flag_count;
	int if_flag;
} t_flags;

typedef struct s_player
{
	double posx;
	double posy;
	double dirx;
	double diry;
	bool w;
	bool s;
	bool a;
	bool d;
	bool left;
	bool right;
	float player_speed;
	float rot_speed;
} t_player;

typedef struct s_map
{
	char **map_file;
	int map_file_height;
	char *map_file_path;
	int map_file_fd;
	int map_height;
	int player_count;
	char direction;
	int map_start;
	char *one_line_map;
	char *south_structure_path;
	char *north_structure_path;
	char *east_structure_path;
	char *west_structure_path;
	char **map;
	char **temp_map;
	int pos_x;
	int pos_y;
	int f_color;
	int c_color;
	t_flags *flags;
} t_map;

typedef struct s_ray
{
	double camerax;
	double raydirx;
	double raydiry;
	double sidedistx;
	double sidedisty;
	double deltadistx;
	double deltadisty;
	double perpwalldist;
	double wallx;
	int mapx;
	int mapy;
	int stepx;
	int stepy;
	int hit;
	int side;
	int lineh;
	int drawstart;
	int drawend;
	int texx;
	int texy;
	double texpos;
} t_ray;

typedef struct s_game
{
	void *mlx;
	void *mlxwin;
	double planex;
	double planey;
	double step;
	int color;
	t_ray *ray;
	t_player *p;
	t_image *no;
	t_image *so;
	t_image *we;
	t_image *ea;
	t_image *image;
	t_map *map;
} t_game;

int exiting(char *str, t_game *game, int status);
void controller_map(t_map *map);
int south_controller_mapler(t_map *map, int i);
int north_controller_mapler(t_map *map, int i);
int east_controller_mapler(t_map *map, int i);
int west_controller_mapler(t_map *map, int i);
int f_controller_mapler(t_map *map, int i);
int c_controller_mapler(t_map *map, int i);
char *get_next_line(int fd);
void error_exit_printing(char *str);
char *path_structure_handler(char *str);
int is_incorrect_name(t_map *map, int i);
int controller_space(t_map *map, int i);
char *colour_path_handler(char *str);
int line_dir_checking(char *map);
int controller_map_sixth(t_map *map);
void read_map(t_map *map);
int ft_err_mapcontrol(char *str, t_map *map, int status);
void map_dimension(t_map *map);
int get_colour_rgb(char *str, t_map *map);
void colour_is_digit(char *tmp, char **str, t_map *map);
void free_array2d(char **str);
void temp_map_creating(t_map *map);
int comma_counter(char *str);
void action_2(t_game *game);
void real_map_finding_height(t_map *map);
void real_map_checking(t_map *map);
void real_map_checking_counter(t_map *map);
void temp_map_creating(t_map *map);
void real_map_reading(t_map *map);
void space_jump(t_map *map, int end);
void init_raycast(t_game *game);
void ft_mlx(t_game *g, int a, int b);
int key_press(int keyCode, t_game *game);
int action_drop(int keyCode, t_game *game);
int gamefunc(t_game *game);
void column_rend(t_game *game, int x, int y);
void wall_height_calculating(t_game *game);
void shot_space_calculating(t_game *game);
void raycast_calculating(t_game *game, int x);
void step_calculating(t_game *g);
void wall_height_x_calculating(t_game *game);
void wall_height_y_calculating(t_game *game);
int ft_space_jump(char *str, int i);
int all_spaces(char *str);
int ft_mlx_exit(t_game *game);
void rotate_2(t_game *g, double dir, double plane);
int is_available_file(char *path);
int space_jump_first(char *str);
void str_copy(char *ret_path, const char *str);
char **split_adv(char const *s, char c, int *split_case);
unsigned int char_length(const char *s, char c);
void flag_free(t_map *map);
void error_2(t_game *game);

#endif
