/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_drawers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:44:21 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/20 13:14:32 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <renderer.h>

void	bresenham(t_map *map, int x1, int y1, int clr)
{
 	int	x0;
	int	y0;
	x0 = map->rndr->pvec->x + (PLY_SIZE / 2);
	y0 = map->rndr->pvec->y + (PLY_SIZE / 2);
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;
	for(;;){
		put_pix_to_img(map, x0, y0, clr);
    		if (x0==x1 && y0==y1) break;
    		e2 = err;
    		if (e2 >-dx) { err -= dy; x0 += sx; }
    		if (e2 < dy) { err += dx; y0 += sy; }
 	 }
}

void	draw_square(t_map *map, int x, int y, int clr)
{
	for (int i = y; i < (y + CELL_SIZE); i++)
	{
		for (int j = x; j < (x + CELL_SIZE); j++)
			put_pix_to_img(map, j, i, clr);
	}
}


void	draw_rect(t_map *map)
{
	int	x;
	int	y;
	

	x = map->rndr->pvec->x;
	y = map->rndr->pvec->y;
	while (y < (map->rndr->pvec->y + PLY_SIZE))
	{
		/*map->rndr->pvec->x = x - 20;*/
		x = map->rndr->pvec->x;
		while (x < (map->rndr->pvec->x + PLY_SIZE))
		{
			put_pix_to_img(map, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
}


void	draw_line(t_map	*map)
{
	double	endx;
	double	endy;
	
	endx = (map->rndr->pvec->x + (PLY_SIZE / 2))  + cos(map->rndr->rot_angl) * 30 ;
	endy = (map->rndr->pvec->y + (PLY_SIZE / 2)) + sin(map->rndr->rot_angl) * 30;
	bresenham(map, (int)endx, (int)endy , 0x03B965);
}	
