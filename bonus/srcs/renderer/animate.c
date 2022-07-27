/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:54:32 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 10:21:02 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

// when door is click to open 
// use the real map to remove the letter from the map 
// when the door is clicked to be removed 
// use the copy map to check for it

t_v	get_index(t_map *map, int i, double *dist)
{
	int	*coord;
	t_v	index;

	*dist = get_dist(map->rndr->pvec->x, map->rndr->wall->rays[i].x,
			map->rndr->pvec->y, map->rndr->wall->rays[i].y);
	coord = get_normalized_coord(map, map->rndr->wall->rays[i].x,
			map->rndr->wall->rays[i].y, map->rndr->wall->arr_angl[i]);
	index.x = coord[0] / CELL_SIZE;
	index.y = coord[1] / CELL_SIZE;
	return (index);
}

void	open_door(t_map *map)
{
	int		i;
	double	dist;
	t_v		index;

	i = -1;
	while (++i < WIDTH)
	{
		if (at_door(map, map->rndr->wall->rays[i].x,
				map->rndr->wall->rays[i].y, i))
		{
			index = get_index(map, i, &dist);
			if (map->rndr->doors->map_cpy[index.y][index.x] == '2'
					&& dist < 100)
			{
				if (map->map[index.y][index.x] == '2')
				{
					map->map[index.y][index.x] = '0';
					break ;
				}
			}
		}
	}
}

t_v	get_pindex(t_map *map)
{
	t_v	index;

	index.x = map->rndr->pvec->x / CELL_SIZE;
	index.y = map->rndr->pvec->y / CELL_SIZE;
	return (index);
}

void	close_door(t_map *map)
{
	int		i;
	double	dist;
	t_v		index;
	t_v		pindex;

	i = -1;
	cast_rays(map, map->rndr->doors->map_cpy);
	while (++i < WIDTH)
	{
		if (at_door(map, map->rndr->wall->rays[i].x,
				map->rndr->wall->rays[i].y, i))
		{
			index = get_index(map, i, &dist);
			pindex = get_pindex(map);
			if (map->map[index.y][index.x] == '0' && dist < 100
			&& index.x != pindex.x && index.y != pindex.x)
			{
				map->map[index.y][index.x] = '2';
				break ;
			}
		}
	}
}

int	open_close_door(int key_code, t_map *map)
{
	if (key_code == KEY_O)
		open_door(map);
	else if (key_code == KEY_C)
		close_door(map);
	return (0);
}
