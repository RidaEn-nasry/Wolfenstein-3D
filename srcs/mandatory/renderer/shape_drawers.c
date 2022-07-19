/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_drawers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:44:21 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/19 18:59:16 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <renderer.h>

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
	map->rndr->pvec->x += (PLY_SIZE / 2);
	map->rndr->pvec->y += (PLY_SIZE / 2);
	/*for (int i = map->rndr->pvec->y; i < (map->rndr->pvec->y + 20); i++)*/
	/*{*/
		/*for (int j = map->rndr->pvec->x ; j < (map->rndr->pvec->x + 20); j++)*/
			/*put_pix_to_img(map, j, i, 0x0000FF);*/
	/*}*/
}

void	draw_line(t_map	*map)
{
	double	endx;
	double	endy;

	endx = cos(map->rndr->rot_angl) * 30;
	endy = sin(map->rndr->rot_angl) * 30;
	

	bresenham(map->rndr->pvec->x, map->rndr->pvec->y, endx, endy, 0xA1EB34);
}	
