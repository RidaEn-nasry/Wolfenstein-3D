/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:11:27 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/15 11:17:53 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

/**
 * @brief given a map of 0 and 1 render a 2d scene with 0 as white squaures and 1 as black squares 
 * 
 * @param map the struct that contains the map to render
 */


/**
 * Cube(wall) size is 64x64x64
 * walls are always 90 degrees to the floor
 *  floor is always flat 
 * FOV of the player is 60 degrees (FOV determines how wide the world looks in fron of the player)
 * the player height is 32 units (half the cube size) 
 * 
 */

#define SQUARE_SIZE 100


t_map   *init_rndr(t_map *map)
{
    map->rndr = malloc(sizeof(*map->rndr));
    map->rndr->fov = 60;
    map->rndr->render_delay = 30;
    map->rndr->pos_x = 2;
    map->rndr->pos_y = 2;
    map->rndr->p_angle = 90;
    map->rndr->ray_incr = (map->rndr->fov / WIDTH);
    map->rndr->ray_prec = 64;
    return (map);
}


void    render_map(t_map *map)
{
    draw_line(1, 2, 44, 56, 0xFF0000, map);
    // map = init_rndr(map);
     
}


