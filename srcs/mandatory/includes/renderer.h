/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:20:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 00:07:21 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef RENDERER_H
# define RENDERER_H

# include <mlx.h>
# include <parser.h>
# include <errors.h>
# include <math.h>
# include <stdlib.h>
#include <limits.h>
# define HEIGHT 1080
# define WIDTH 1920 
# define SCL_FAC 0.4
# define CELL_SIZE 18
# define SPEED 2
# define PLY_SIZE 6
# define NUM_RAYS WIDTH / 2
// key codes
# define UP 13   
# define DOWN 1 
# define RIGHT 124
# define LEFT 123
# define EXIT 53

void    renderer(t_map *map);
void    render_map(t_map *map);
void    rasterize_vector(int x1, int y1, int x2, int y2, int c, t_map *map);

// initilization stuff 
t_map	*new_img(t_map *map);
t_map	*init_mlx(t_map *map);
t_map   *init_rndr(t_map *map);

// math utils
double  degtorad(double degree);

// mlx utils 
void	put_pix_to_img(t_map *map, int x, int y, int clr);


// drawers 
void	draw_rect(t_map *map, double x, double y, int height, int width);
void	draw_square(t_map *map, int x, int y, int clr);
void	draw_map(t_map *map, int flag);
void	draw_player(t_map *map);
void	draw_line(t_map *map, double angle, int len);


// moves
int	move_player(int key_code, t_map *map);
void	update_ang(t_map *map);
void	bresenham(t_map *map, int x1, int y1, int clr);


// rays
void	cast_rays(t_map *map);


// 3d projection 
void	project3d(t_map	*map);

// double arr distance 
t_darr  *add_dist(t_map *map, double value);
#endif
