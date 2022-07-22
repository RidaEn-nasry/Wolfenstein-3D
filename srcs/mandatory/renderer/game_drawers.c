/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:12 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 17:33:42 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
void	draw_rays(t_map *map)
{
	// double	startx;
	// double	starty;
	size_t		i;

	i = 0;	
	// startx = map->rndr->pvec->x + 2;
	// starty = map->rndr->pvec->y + 2;
	
	// printf("rays length: %lu\n", map->rndr->wall->rys_len);
	while (i < map->rndr->wall->rys_len)
	{
		printf("ray to %f, %f\n", map->rndr->wall->rays[i].x, map->rndr->wall->rays[i].y);
		bresenham(map, map->rndr->wall->rays[i].x, map->rndr->wall->rays[i].y, 0x03B965);
		i++;
	}
}


void	draw_minimap(t_map	*map)
{
	size_t	x;
	size_t	y;
	int		i;
	int		j;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (map->map[i])
	{
		x = 0;
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				draw_square(map, x, y, 0xFF0000);
			else
				draw_square(map, x , y, 0xFFFFFFF);
			x += 16;
			j++;
		}
		i++;
		y += 16;
	}
	draw_player(map);
	draw_rays(map);
}

// }
void	draw_player(t_map *map)
{	
	draw_rect(map, map->rndr->pvec->x, map->rndr->pvec->y, PLY_SIZE, PLY_SIZE);
}

void	draw_map(t_map *map, int flag) {
	int	x;
	int	y;
	bool	p;

	p = false;
	x = 0;  
	y = 0;
	for (int i = 0; map->map[i]; i++)
	{
		x = 0;
		for (int j = 0; map->map[i][j]; j++)
		{
			if (map->map[i][j] == 'N' && !flag)
			{
				p = true;
				map->rndr->pvec->x = x;
				map->rndr->pvec->y = y;
			}			
			x += 16;
		}
		y += 16;
	}
	if (flag == 1 || p == true)
	{
		// draw_player(map);
		cast_rays(map);	
		// for (size_t i = 0; i < map->rndr->dist->len; i++)
		// {
		// 	printf("dist: %lf\n", map->rndr->dist->arr[i]);
		// }
		project3d(map);
		// draw_minimap(map);
	}
}

