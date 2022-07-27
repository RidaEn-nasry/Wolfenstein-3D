/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:11:27 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 09:45:14 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
/*
 * Cube(wall) size is 64x64x64
 * walls are always 90 degrees to the floor
 *  floor is always flat 
 * FOV of the player is 60 degrees 
 * (FOV determines how wide the world looks in fron of the player)
 * the player height is 32 units (half the cube size) 
 * 
 */
int	red_cross(t_map *map)
{
	exit_free_if(true, NULL, map, 0);
	return (0);
}

int	key_react(int key_code, t_map *map)
{
	open_close_door(key_code, map);
	move(map, key_code);
	if (key_code == EXIT)
		exit_free_if(true, "Bey Bey", map, 0);
	update_screen(map);
	return (0);
}

void	render_map(t_map *map)
{
	map = init_rndr(map);
	draw_map(map, 0);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
	mlx_hook(map->mlx->win, 2, 1L << 0, key_react, map);
	mlx_hook(map->mlx->win, 17, 0L, &red_cross, map);
	play_sound(map);
	mlx_hook(map->mlx->win, MOTION_NOTIFY,
		1L << 6, mouse_hook, map);
	mlx_loop(map->mlx->mlx);
}
