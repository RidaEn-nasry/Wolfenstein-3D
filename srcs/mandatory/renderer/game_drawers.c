/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:12 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 14:30:14 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

// void	draw_minimap(t_map	*map)
// {
// 	size_t	x;
// 	size_t	y;
	
	
// 	x = 0;
// 	y = 0;
// 	while (y < map->h)
// 	{
// 		x = 0;
// 		while (x < map->w)
// 		{
// 			if (map->map[y][x] == '1')
// 				draw_square(map, x, y, 0xFF0000);
// 			else
// 				draw_square(map, x , y, 0xFFFFFFF);	
// 			x++;
// 		}
// 		y++;
// 	}



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
			if (map->map[i][j] == '1' )
				draw_square(map, x, y, 0xFF0000);
			else
				draw_square(map, x , y, 0xFFFFFFF);
			if (map->map[i][j] == 'N' && !flag)
			{
				p = true;
				map->rndr->pvec->x = x;
				map->rndr->pvec->y = y;
			}			
			x += CELL_SIZE;
		}
		y += CELL_SIZE;
	}
	if (flag == 1 || p == true)
	{
		draw_player(map);
		cast_rays(map);	
		// for (size_t i = 0; i < map->rndr->dist->len; i++)
		// {
		// 	printf("dist: %lf\n", map->rndr->dist->arr[i]);
		// }
		project3d(map);
	}
}

