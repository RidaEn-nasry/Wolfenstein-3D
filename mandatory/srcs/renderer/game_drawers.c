/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:13:16 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/25 21:24:05 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	draw_player(t_map *map)
{
	double	prev_x;
	double	x0;
	double	y0;

	x0 = (map->rndr->pvec->x * SCL_FAC);
	y0 = (map->rndr->pvec->y * SCL_FAC);
	prev_x = x0 ;
	while (y0 <= ((map->rndr->pvec->y * SCL_FAC) + PLY_SIZE))
	{
		x0 = prev_x;
		while (x0 <= ((map->rndr->pvec->x * SCL_FAC) + PLY_SIZE))
		{	
			put_pix_to_img(map, x0, y0, 0xB0B0B0);
			x0++;
		}
		y0++;
	}
}

void	init_angl(t_map *map, char c)
{
	if (c == 'N')
		map->rndr->rot_angl = degtorad(270);
	if (c == 'W')
		map->rndr->rot_angl = degtorad(180);
	if (c == 'S')
		map->rndr->rot_angl = degtorad(90);
	if (c == 'E')
		map->rndr->rot_angl = degtorad(0);
}

bool	isplayer(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'W')
		return (true);
	return (false);
}

void	draw_map_assistant(t_map *map, t_drawmap *draw)
{
	init_angl(map, map->map[draw->i][draw->j]);
	draw->p = true;
	map->rndr->pvec->x = draw->x;
	map->rndr->pvec->y = draw->y;
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
	if (flag == 1 || draw.p == true)
	{
		cast_rays(map);
		project3d(map);
	}
}
