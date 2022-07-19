/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:11:27 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/19 13:26:51 by ren-nasr         ###   ########.fr       */
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

void	cast_rays() {/*cast all rays here*/}


void	draw_rect(t_map *map, int x, int y)
{
	for (int i = y; i < (y + 20); i++)
	{
		for (int j = x; j < (x + 20); j++)
			put_pix_to_img(map, j, i, 0x0000FF);
	}
}

int	move_ply(int key_code, t_map *map)
{
	(void)key_code;
	(void)map;
	/*map->rndr->pvec->x += 10;*/
	/*map->rndr->pvec->y += 10;*/
	/*mlx_clear_window(map->mlx->mlx, map->mlx->win);*/
	/*draw_rect(map);*/
	/*mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);*/
	return (0);
}


void	draw_square(t_map *map, int x, int y, int clr)
{
	for (int i = y; i < (y + CELL_SIZE); i++)
	{
		for (int j = x; j < (x + CELL_SIZE); j++)
			put_pix_to_img(map, j, i, clr);

	}
}

void	draw_player(t_map *map, int x, int y)
{
	draw_rect(map, x, y);	
}

void	draw_map(t_map *map) {

	int	x;
	int	y;

	x = 400;  
	y = 300;
	for (int i = 0; map->map[i]; i++)
	{
		x = 400;
		for (int j = 0; map->map[i][j]; j++)
		{
			if (map->map[i][j] == '1')
				draw_square(map, x,y, 0xFF0000);
			else if (map->map[i][j] == '0')
				draw_square(map, x,y,0xFFFFFFF);
			x += CELL_SIZE;
		}
		y += CELL_SIZE;
	}
	draw_player(map, x - 100, y - 250);
}
void    render_map(t_map *map)
{
	map = init_rndr(map);
	/*draw_rect(map);*/
	draw_map(map);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
	/*mlx_key_hook(map->mlx->win, move_ply, map);*/
	mlx_loop(map->mlx->mlx);
}

