/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:11:27 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/20 22:10:00 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
/*
 * Cube(wall) size is 64x64x64
 * walls are always 90 degrees to the floor
 *  floor is always flat 
 * FOV of the player is 60 degrees (FOV determines how wide the world looks in fron of the player)
 * the player height is 32 units (half the cube size) 
 * 
 */


void    render_map(t_map *map)
{
	map = init_rndr(map);
	/*draw_rect(map);*/
	draw_map(map, 0);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
	mlx_hook(map->mlx->win, 2, 1L<<0, move_player, map);
	mlx_loop(map->mlx->mlx);
}

