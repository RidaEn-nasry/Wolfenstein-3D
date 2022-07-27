/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:20:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 22:48:58 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H  

# include <mlx.h>
# include <parser.h>
# include <errors.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>

# define SCL_FAC 0.25
# define CELL_SIZE 64

// # define SPEED 2
# define PLY_SIZE 8

// key codes
# define KEY_W 13   
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define RIGHT 124
# define LEFT 123
# define EXIT 53
# define KEY_SPC 49
# define KEY_C 8 
# define KEY_O 31 
// moves 
double		get_turn_spd(int x, int prev_x);

// xlib macros
# define MOTION_NOTIFY 6

void		renderer(t_map *map);
void		render_map(t_map *map);

// initilization stuff 
t_map		*new_img(t_map *map);
t_map		*init_mlx(t_map *map);
t_map		*init_rndr(t_map *map);

// math utils
double		degtorad(double degree);
double		get_dist(double x0, double x1, double y0, double y1);
// mlx utils 
void		put_pix_to_img(t_map *map, int x, int y, int clr);

// drawers 
void		draw_square(t_map *map, int x, int y, int clr);
void		draw_map(t_map *map, int flag);
void		draw_player(t_map *map, double x, double y);
void		draw_minimap(t_map	*map, double x, double y);

// casting
double		denormalize_angle(double angle);
void		get_txtr(t_map *map, double ray_angl, int i);
double		get_dist(double x0, double x1, double y0, double y1);
t_map		*get_smaller_dist(t_map *map, t_wall *wallh, t_wall *wallv);
t_vector	get_horiz_inters(t_map *map, t_wall *wall, t_vector start);
bool		check_inters_h(t_map *map, t_vector *nwall,
				t_wall *wall, char **which_map);
bool		check_inters_v(t_map *map, t_vector *nwall,
				t_wall *wall, char **which_map);
t_vector	get_vert_inters(t_map *map, t_wall *wall, t_vector start);
void		set_biggest_dist(t_wall *wall);
void		set_wall_info(t_map *map, int i);
void		project_ceiling(t_map *map, int i);
void		project_wall(t_map *map, int i, int txtr_x);
void		project_floor(t_map *map, int i);

// hooks 
int			mouse_hook(int x, int y, t_map *map);
int			key_react(int key_code, t_map *map);
int			open_close_door(int key_code, t_map *map);

// moves
void		update_ang(t_map *map, double *ang);
void		bresenham(t_map *map, int x1, int y1, int clr);
void		update_pos(double *x, double *y, t_map *map);
void		move(t_map *map, int mv);
bool		inside_wall(double x, double y, t_map *map);
int			mouse_hook(int x, int y, t_map *map);
void		move(t_map *map, int mv);
void		move_right(t_map *map);
void		move_left(t_map *map);

// rays
void		cast_rays(t_map *map, char **which_map);

// 3d projection 
void		project3d(t_map	*map);

// normalize ang
double		normalize_ang(double angle);
double		denormalize_angle(double angle);
int			*get_normalized_coord(t_map *map, double x, double y, double ang);
// double arr distance 
t_map		*add_dist(t_map *map, double value, double ray_angl);
t_map		*add_ray_coor(t_map *map, double x, double y);

// utils

bool		ray_is_down(double angle);
bool		ray_is_right(double angle);
double		normalize_ang(double angle);
int			get_mouse_x(t_map *map);
void		update_screen(t_map *map);
t_map		*add_door(t_map *map, double x, double y);
bool		at_door(t_map *map, double x, double y, int i);
bool		at_sprit(t_map *map, int i);
void		init_angl(t_map *map, char c);
bool		isplayer(char c);

// sounds 
void		play_sound(t_map *map);

#endif
