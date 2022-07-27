/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 05:40:13 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 22:03:36 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

t_vector	get_horiz_inters(t_map *map, t_wall *wall, t_vector start)
{
	t_vector	inters;

	inters.y = floor(start.y / CELL_SIZE) * CELL_SIZE;
	if (ray_is_down(map->rndr->wall->ray_angl))
		inters.y += CELL_SIZE;
	inters.x = start.x + ((inters.y - start.y)
			/ tan(map->rndr->wall->ray_angl));
	wall->step->y = CELL_SIZE;
	if (!ray_is_down(map->rndr->wall->ray_angl))
		wall->step->y *= -1;
	wall->step->x = CELL_SIZE / tan(map->rndr->wall->ray_angl);
	if (ray_is_right(map->rndr->wall->ray_angl) && wall->step->x < 0)
		wall->step->x *= -1;
	else if (!ray_is_right(map->rndr->wall->ray_angl) && wall->step->x > 0)
		wall->step->x *= -1;
	return (inters);
}

t_vector	get_vert_inters(t_map *map, t_wall *wall, t_vector start)
{
	t_vector	inters;

	inters.x = floor(start.x / CELL_SIZE) * CELL_SIZE;
	map->rndr->wall->ray_angl = normalize_ang(map->rndr->wall->ray_angl);
	if (ray_is_right(map->rndr->wall->ray_angl))
		inters.x += CELL_SIZE;
	inters.y = start.y + (inters.x - start.x) * tan(map->rndr->wall->ray_angl);
	wall->step->x = CELL_SIZE;
	if (!ray_is_right(map->rndr->wall->ray_angl))
		wall->step->x *= -1;
	wall->step->y = CELL_SIZE * tan(map->rndr->wall->ray_angl);
	if (!ray_is_down(map->rndr->wall->ray_angl) && wall->step->y > 0)
		wall->step->y *= -1;
	else if (ray_is_down(map->rndr->wall->ray_angl) && wall->step->y < 0)
		wall->step->y *= -1;
	return (inters);
}

bool	check_inters_h(t_map *map, t_vector *nwall, \
t_wall *wall, char **which_map)
{
	t_v	index;

	index.x = nwall->x / CELL_SIZE;
	index.y = nwall->y / CELL_SIZE;
	if (which_map[index.y][index.x] == '1'
		|| which_map[index.y][index.x] == '2')
	{
		if (!ray_is_down(map->rndr->wall->ray_angl))
			nwall->y += 1;
		map->txtr->found_h = true;
		wall->wall->x = nwall->x;
		wall->wall->y = nwall->y;
		return (true);
	}
	else
	{
		nwall->x += wall->step->x;
		nwall->y += wall->step->y;
		return (false);
	}
}

bool	check_inters_v(t_map *map, t_vector *nwall, \
t_wall *wall, char **which_map)
{
	t_v	index;

	index.x = nwall->x / CELL_SIZE;
	index.y = nwall->y / CELL_SIZE;
	if (which_map[index.y][index.x] == '1'
		|| which_map[index.y][index.x] == '2')
	{
		if (!ray_is_right(map->rndr->wall->ray_angl))
			nwall->x += 1;
		map->txtr->found_v = true;
		wall->wall->x = nwall->x;
		wall->wall->y = nwall->y;
		return (true);
	}
	else
	{
		nwall->x += wall->step->x;
		nwall->y += wall->step->y;
		return (false);
	}
}
