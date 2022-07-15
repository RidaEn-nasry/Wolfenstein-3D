/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:20:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/15 11:17:18 by ren-nasr         ###   ########.fr       */
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

void    renderer(t_map *map);
void    render_map(t_map *map);
void    draw_line(int x1, int y1, int x2, int y2, int c, t_map *map);

#endif