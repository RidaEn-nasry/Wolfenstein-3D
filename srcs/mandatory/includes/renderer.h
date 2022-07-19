/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:20:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/19 18:44:39 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef RENDERER_H
# define RENDERER_H

# include <mlx.h>
# include <parser.h>
# include <errors.h>
# include <math.h>

# define HEIGHT 1080
# define WIDTH 1920
# define RAYS WIDTH 
# define SCL_FAC 1
# define CELL_SIZE (64 * SCL_FAC)
# define SPEED 8
# define PLY_SIZE 16
// key codes
# define UP 13   
# define DOWN 1 
# define RIGHT 2 
# define LEFT 0
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
void	draw_rect(t_map *map);
void	draw_square(t_map *map, int x, int y, int clr);
void	draw_map(t_map *map, int flag);
void	draw_player(t_map *map);
void	draw_line(t_map *map);


// moves
int	move_player(int key_code, t_map *map);

#endif
