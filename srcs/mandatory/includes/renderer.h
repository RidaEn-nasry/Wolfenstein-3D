/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:20:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/19 13:31:39 by ren-nasr         ###   ########.fr       */
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

#endif
