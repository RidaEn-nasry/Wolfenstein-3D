/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:12 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/20 17:26:07 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	draw_player(t_map *map)
{
	draw_rect(map);
	draw_line(map);	
	//draw_line(map, x + (x / 2), y + (y / 2));
}

void	draw_map(t_map *map, int flag) {

	int	x;
	int	y;

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
				map->rndr->pvec->x = x ;
				map->rndr->pvec->y = y ;
				draw_player(map);
			}
			
			x += CELL_SIZE;
		}
		y += CELL_SIZE;
	}
	if (flag == 1)
		draw_player(map);
}

