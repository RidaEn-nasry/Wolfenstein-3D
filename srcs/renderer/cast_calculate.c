/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 05:42:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 16:49:59 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

double	normalize_ang(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

t_map	*get_smaller_dist(t_map *map, t_wall *wallh \
, t_wall *wallv)
{
	t_vector	start;
	t_wall		*end;
	double		distance_v;
	double		distance_h;

	start.x = map->rndr->pvec->x + (PLY_SIZE / 2);
	start.y = map->rndr->pvec->y + (PLY_SIZE / 2);
	distance_h = get_dist(start.x, wallh->wall->x, start.y, wallh->wall->y);
	distance_v = get_dist(start.x, wallv->wall->x, start.y, wallv->wall->y);
	if (distance_h <= distance_v)
	{
		end = wallh;
		map->txtr->found_h = true;
		map->txtr->found_v = false;
		map = add_dist(map, distance_h, map->rndr->wall->ray_angl);
	}
	else
	{
		end = wallv;
		map->txtr->found_v = true;
		map->txtr->found_h = false;
		map = add_dist(map, distance_v, map->rndr->wall->ray_angl);
	}
	map = add_ray_coor(map, end->wall->x, end->wall->y);
	return (map);
}
