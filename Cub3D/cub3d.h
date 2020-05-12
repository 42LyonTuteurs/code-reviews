/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:07:53 by lolopez           #+#    #+#             */
/*   Updated: 2020/05/05 15:39:18 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "./getnextline/get_next_line.h"
# include "./printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <time.h>
# define MINIMAP_PIX	15
# define FOV_DEG 60.0
# define TILE_SIZE 200
# define STEP_SIZE 30
# define RAD_ANG 6
# define MINIMAP_RATIO 2
# define UP	0x7a
# define BACK 0x73
# define LEFT 0x71
# define RIGHT 0x64
# define TURNR 0xff53
# define TURNL 0xff51
# define EXIT 0xff1b
# define ACTION 0x20

typedef struct	s_imag
{
	void				*img_ptr;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
	int					height;
	int					width;
}				t_imag;

typedef struct	s_mlx
{
	void				*mlx_ptr;
	void				*win;
	t_imag				img;
}				t_mlx;

typedef struct	s_vect
{
	double				x;
	double				y;
}				t_vect;

typedef struct	s_ray
{
	t_vect				primdist;
	t_vect				a;
}				t_ray;

typedef struct	s_2d_line
{
	double				a;
	double				b;
	double				c;
}				t_2d_line;

typedef struct	s_pos
{
	int					x;
	int					y;
}				t_pos;

typedef struct	s_cast
{
	double				alpha;
	double				orientation;
	t_vect				vertical;
	t_vect				horizontal;
	t_pos				murx;
	t_pos				mury;
	struct s_ray		h;
	struct s_ray		v;
	struct s_2d_line	math;
	double				dist;
}				t_cast;

typedef struct	s_perso
{
	t_vect				pos;
	t_vect				direction;
	t_vect				*vector;
	double				*distance;
	int					*side;
	int					*offset;
	double				angle;
	t_vect				plane;
	t_vect				start_s;
	t_vect				stop_v;
	t_vect				*tab_vect_init;
	t_vect				direction_init;
}				t_perso;

typedef struct	s_map
{
	int					resolution_w;
	int					resolution_h;
	t_pos				minimap_res;
	char				*texture_nord;
	char				*texture_sud;
	char				*texture_ouest;
	char				*texture_est;
	char				*texture_sprite;
	int					couleur_plafond;
	int					couleur_sol;
	char				*mapinit;
	char				**map;
	int					map_w;
	int					map_h;
	int					id_sprite;
	struct s_sprite		*sprite;
	int					(*ft_parse_cub[9])(char *str, struct s_map *carte);
	char				tabindex[9];
	t_imag				*text;
	int					sdl;
}				t_map;

typedef struct	s_sprite
{
	int					exist;
	int					pos;
	t_vect				middle;
	t_vect				p_start;
	t_vect				p_end;
	int					istart;
	int					iend;
	double				dist;
	double				hauteur;
	double				cutstart;
	double				cutend;
	int					order;
	double				mid_rad;
	struct s_ray_sprite	*ray;
	struct s_2d_line	math;
}				t_sprite;

typedef	struct	s_ray_sprite
{
	double				point;
	int					dist;
	int					i;
	struct s_ray_sprite	*next;
}				t_ray_sprite;

typedef struct	s_hub
{
	t_imag				*text;
	int					i;
	int					life;
	int					frame;
}				t_hub;

typedef struct	s_cub_data
{
	t_mlx				mlx;
	t_perso				perso;
	t_map				carte;
	t_imag				minimap;
	t_hub				*bon;
	int8_t				key[7];

}				t_cub_data;

/*
** --------- Parsing ----------
*/

int				test_file_name(char *str);
int				too_many_args(t_map *carte, char *var);
int				not_enough_args(t_map *carte, char *var);
int				args_checker(t_map *carte);
void			map_error(t_map *carte);
int				err_gnl(t_map *carte, char **line);
void			read_color(int *red, int *green, int *blue, char *str);
void			toomucccommas(char *str, t_map *carte);
int				ft_couleur_sol(char *str, t_map *carte);
int				ft_couleur_plafond(char *str, t_map *carte);
int				ft_resolution(char *str, t_map *carte);
void			fill_resolution(char *str, t_map *carte);
void			res_eq(t_map *carte, int w, int h);
int				resolution_err(int i, char *str);
int				ft_text_nord(char *str, t_map *carte);
int				ft_text_sud(char *str, t_map *carte);
int				ft_text_est(char *str, t_map *carte);
int				ft_text_ouest(char *str, t_map *carte);
int				ft_text_sprite(char *str, t_map *carte);
int				ft_map(char *str, t_map *carte);
void			fill_tab_map(t_map *carte);
int				malloc_tab_map(t_map *carte);
int				map_width(t_map *carte);
int				primary_map_error_checker(t_map *carte);
int				map_wall_error_checker(t_map *carte);
int				fouillefouine(t_map *c, int y, int x);
int				map_only_one_player(t_map *carte);
int				walls_outside(t_map *carte);
void			tab_init(t_map *carte);
void			ft_map_struct_init(t_map *carte);
int				ft_open_cub(t_map *carte, char *map_path);
int				is_a_wall(char *str, t_map *carte);
int				ft_read_cub(t_map *carte, int cub);
int				ft_search_pref(t_map *carte, char *str);
int				mapfirst(t_map *carte);

/*
** --------- MLX ----------
*/

int				go_forth(t_cub_data *param);
int				go_backward(t_cub_data *param);
int				go_left(t_cub_data *param);
int				go_right(t_cub_data *param);
int				turn_left(t_cub_data *param);
int				turn_right(t_cub_data *param);
int				turn_mouse(t_cub_data *param, double angle);
int				attack(t_cub_data *c);
int				mouse_move(int x, int y, t_cub_data *cub);
int				key_press(int keycode, t_cub_data *param);
int				key_release(int keycode, t_cub_data *param);
int				load_xpm(t_mlx *mlx, char *file, t_imag *img);
int				ft_keyhook(t_cub_data *param);
int				event_loop(t_cub_data *cub);
int				get_texture(t_cub_data *cub);
int				init_data(t_cub_data *cub);
int				keyp(int keycode, t_cub_data *param);
int				load_xpm(t_mlx *mlx, char *file, t_imag *img);

/*
** ///////// GAME /////////////
*/

int				game_win(t_cub_data *cub, t_mlx *mlx, int bmp);
int				init_game(t_cub_data *cub);
int				ceil_floor(t_cub_data *cub);
int				new_img(t_cub_data *cub, int screen);
int				primary_pos_perso(t_cub_data *cub);
int				init_angle(char direction, t_perso *perso);
int				cast_ray(t_cub_data *cub, int i);

/*
** --------- WALLS ----------
*/

int				aff_wall(t_cub_data *cub);
int				paint_wall(t_cub_data *cub, int i, int t, double hauteur);
int				calc_wall_orientation(int xy, t_vect vect, t_cub_data *cub,\
int i);
double			correct_distance(int i, double dist, t_cub_data *cub);
int				clean_cub_perso(t_cub_data *cub);
int				malloc_cub_perso(t_cub_data *cub);
double			projection_plane(t_cub_data *cub);
int				calc_xy(t_cub_data *cub, int i, double *distx, double *disty);
t_ray			calc_h(t_cub_data *cub, double alpha, double orientation);
t_ray			calc_v(t_cub_data *cub, double alpha, double orientation);
double			calc_wall_dist(t_cub_data *cub, int i, t_cast *cast);
t_vect			pos_wall_x(t_cub_data *cub, t_cast *ray);
t_vect			pos_wall_y(t_cub_data *cub, t_cast *ray);

/*
** --------- Sprites ----------
*/

int				ft_sprite_tab_create(t_map *carte);
void			sprite_tab_init(t_map *carte);
void			ft_sprite_pos_init(t_map *carte);
double			calc_cutstart(t_cast *cast, t_cub_data *cub, int id);
double			calc_cutend(t_cast *cast, t_cub_data *cub, int id);
void			vect_xy(t_cast *cast, t_cub_data *cub, int i, int id);
int				check_exist(t_cast *cast, t_cub_data *cub, int i, int id);
int				check_ok_spri(t_cub_data *cub, t_pos ok, t_vect point, int id);
void			ray_sprite_list(t_cast *cast, t_cub_data *cub, int i, int id);
t_pos			def_ok(t_cub_data *cub, t_vect point, int id);
t_pos			def_ray(t_cast *cast);
int				sprite_struct_clean(t_cub_data *cub);
void			calc_sprite_angle(t_cub_data *cub, int id);
void			calc_sprite_dist(t_cub_data *cub, int id);
void			calc_sprite_segm(t_cub_data *cub, int id);
int				calc_sprite(t_cub_data *cub, int i, t_cast *cast);
void			sprite_vect_math(t_cub_data *cub);
void			sprite_abc(t_cub_data *cub, int id);
void			sort_sprites(t_cub_data *cub);
int				mur_derriere(t_cub_data *cub, int id, int i, t_cast *cast);
void			print_sprite(t_cub_data *cub, int id);
void			paint_sprite_col(t_cub_data *cub, int id, int i, double offset);
t_pos			paint_sprite_col2(t_cub_data *cub, int id);
void			print_sorted_sprite(t_cub_data *cub);
int				sprite_t(t_cub_data *c, int id);

/*
** --------- Maths ----------
*/

t_vect			calc_vect(double angle);
void			calc_grosse_matrice(t_vect *vecteur, double angle);
t_vect			*tab_vect_init(t_cub_data *cub);
double			degrees_to_radian(double angle_in_degrees);
void			incr_angl(double *angle, int sign, double increment);
double			calc_alpha(double angle);
double			new_angle(double calcul);
t_2d_line		line_math(t_cub_data *cub, t_cast ray);
int				inter_2d_line_line(t_2d_line l1, t_2d_line l2, t_vect *result);

/*
** --------- BMP ----------
*/

void			screenshot(t_cub_data *cub);
void			convert_bits(uint8_t *header, long int data);
void			bmp_h(t_cub_data *cub, int fd);
void			bmp_colors(t_cub_data *cub, int fd);
int				create_bmp(t_cub_data *cub);
int				exit_bmp(t_cub_data *param);

/*
** --------- Minimap ----------
*/

int				mini_map_win(t_cub_data *cub);
int				mini_map_print(t_cub_data *cub);
void			print_pos(t_cub_data *cub);
void			print_pos_two(t_cub_data *cub);
void			print_map(t_cub_data *cub, t_pos *i, t_vect *start,\
t_vect *pospix);
void			color_of_the_pix(t_cub_data *cub, t_pos *i,\
t_vect *start, int num);

/*
** --------- Exit ----------
*/

int				ft_error_parsing(t_map *carte, char *str, int text);
int				ft_error_g(t_cub_data *cub, char *str, int text);
void			free_text(t_map *carte);
void			clear_map_struct(t_map *carte);
int				exit_propre(t_cub_data *param);

/*
** --------- BoNuS GaMe ----------
*/

void			init_game_bonus(t_cub_data *cub);
int				get_texture_bonus(t_cub_data *cub);
int				get_bonus(t_cub_data *cub);
int				get_hub_text(t_cub_data *cub);
void			ft_draw_hub(t_cub_data *c, int t);
int				print_hub(t_cub_data *c);
int				hub_text(t_cub_data *c);
void			check_rousta(t_cub_data *c);
void			roustata(t_cub_data *c, int y, int x);
int				clean_bonus(t_cub_data *c);

#endif
