/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_drawers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:44:21 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 16:08:11 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

// void	draw_square(t_map *map, int x, int y, int clr, long size)
// {
// 	int		i;
// 	int		j;

// 	i = y;
// 	while (i < (y + size))
// 	{
// 		j = x;
// 		while (j < (x + size))
// 		{
// 			put_pix_to_img(map, j, i, clr);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_rect(t_map *map, double x, double y, int width, int height)
// {
// 	double	prev_x;
// 	double	x0;
// 	double	y0;
// 	int		pixel;

// 	prev_x = x;
// 	x0 = x + width;
// 	y0 = y + height;
// 	while (x <= x0)
// 	{
// 		while (y <= y0)
// 		{
// 			map->txtr->north_vec->y = (y - map->rndr->wall->wall_top_pixel)
// 				* (CELL_SIZE / map->rndr->wall->wall_height);
// 			pixel = map->txtr->north_data[(int)(map->txtr->north_vec->y
// 					* map->txtr->size_line + map->txtr->north_vec->x
// 					* (map->txtr->bpp / 8))];
// 			put_pix_to_img(map, x, y, pixel);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	draw_line(t_map	*map, double angle, int len)
// {
// 	double	endx;
// 	double	endy;

// 	endx = (map->rndr->pvec->x + (PLY_SIZE / 2)) + cos(angle) * len;
// 	endy = (map->rndr->pvec->y + (PLY_SIZE / 2)) + sin(angle) * len;
// }	
