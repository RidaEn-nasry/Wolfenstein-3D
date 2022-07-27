/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:14:52 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 09:47:34 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	update_x_y(double ang, double *x, double *y)
{
	if (!ray_is_down(ang) && ray_is_right(ang))
	{
		*x += 1;
		*y -= 1;
	}
	else if (!ray_is_down(ang) && !ray_is_right(ang))
	{
		*y -= 1;
		*x -= 1;
	}
	if (ray_is_down(ang) && ray_is_right(ang))
	{
		*y += 1;
		*x += 1;
	}
	else if (ray_is_down(ang) && !ray_is_right(ang))
	{
		*y += 1;
		*x -= 1;
	}
}

int	*get_normalized_coord(t_map *map, double x, double y, double ang)
{
	int	*coord;

	exit_free_if(!(coord = malloc(sizeof(*coord) * 2)),
		"Error:\n\tmalloc failed", map, 1);
	ang = normalize_ang(ang);
	update_x_y(ang, &x, &y);
	coord[0] = x;
	coord[1] = y;
	return (coord);
}

bool	at_door(t_map *map, double x, double y, int i)
{
	int	index_x;
	int	index_y;
	int	*coord;

	coord = get_normalized_coord(map, x, y, map->rndr->wall->arr_angl[i]);
	index_x = coord[0] / CELL_SIZE;
	index_y = coord[1] / CELL_SIZE;
	if (map->rndr->doors->map_cpy[index_y][index_x] == '2')
		return (true);
	return (false);
}
