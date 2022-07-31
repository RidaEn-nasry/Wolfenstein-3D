/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:12 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/28 13:31:41 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	draw_minimap(t_map *map, double x, double y)
{
	t_v		index;

	index.y = -1;
	while (map->map[++index.y])
	{
		x = 0;
		index.x = -1;
		while (map->map[index.y][++index.x])
		{
			if (map->map[index.y][index.x] == '1'
				|| map->map[index.y][index.x] == '2')
			{
				if (map->map[index.y][index.x] == '2')
					draw_square(map, x, y, 0x00FF00);
				else if (map->map[index.y][index.x] == '1')
					draw_square(map, x, y, 0xFF0000);
			}
			else
				draw_square(map, x, y, 0xFFFFFFF);
			x += (CELL_SIZE * SCL_FAC);
		}
		y += (CELL_SIZE * SCL_FAC);
	}
	draw_player(map, map->rndr->pvec->x, map->rndr->pvec->y);
}

void	draw_player(t_map *map, double x, double y)
{
	int		x0;
	int		y0;
	double	x1;
	double	y1;

	x0 = (x * SCL_FAC);
	y0 = (y * SCL_FAC);
	if (x0 % 8 > 0 && x0 % 8 < 8 && x0 / 8)
		x0 = (x0 / 8) * 8;
	if (y0 % 8 > 0 && y0 % 8 < 8 && y0 / 8)
		y0 = ((y0 / 8) * 8);
	x1 = x0;
	y1 = y0;
	while (x0 < x1 + PLY_SIZE)
	{
		y0 = y1;
		while (y0 < y1 + PLY_SIZE)
		{
			put_pix_to_img(map, x0, y0, 0xb0b0b0);
			y0++;
		}
		x0++;
	}
}

void	draw_map_assistant(t_map *map, t_drawmap *draw)
{
	init_angl(map, map->map[draw->i][draw->j]);
	draw->p = true;
	map->rndr->pvec->x = draw->x;
	map->rndr->pvec->y = draw->y;
	exit_free_if(!(map->rndr->doors->map_cpy = ft_doubdup(map->map)),
		"Error:\n\tmalloc failed", map, 1);
}

void	set_new(t_map *map, bool flag, t_drawmap *draw)
{
	if (flag == 1 || draw->p == true)
	{
		cast_rays(map, map->map);
		project3d(map);
		draw_minimap(map, 0, 0);
	}
}

void	draw_map(t_map *map, int flag)
{
	t_drawmap	draw;

	draw.p = false;
	draw.y = 0;
	draw.i = -1;
	while (map->map[++draw.i])
	{
		draw.x = 0;
		draw.j = -1;
		while (map->map[draw.i][++draw.j])
		{
			if (isplayer(map->map[draw.i][draw.j]) && !flag)
			{
				draw_map_assistant(map, &draw);
				break ;
			}		
			draw.x += CELL_SIZE;
		}
		draw.y += CELL_SIZE;
	}
	set_new(map, flag, &draw);
}
