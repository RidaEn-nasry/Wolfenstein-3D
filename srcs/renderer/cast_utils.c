/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:46:49 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 22:10:04 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

double	denormalize_angle(double angle)
{
	angle = remainder(angle - M_PI, 2 * M_PI);
	if (angle < 0)
		angle += M_PI * 2;
	return (angle);
}

void	get_txtr_assist(t_map *map, double ray_angl)
{
	if (!ray_is_down(ray_angl) && !ray_is_right(ray_angl))
	{
		map->txtr->data_h = map->txtr->south_data;
		map->txtr->data_v = map->txtr->east_data;
	}
	else if (ray_is_down(ray_angl) && ray_is_right(ray_angl))
	{
		map->txtr->data_h = map->txtr->north_data;
		map->txtr->data_v = map->txtr->west_data;
	}
	else if (ray_is_down(ray_angl) && !ray_is_right(ray_angl))
	{
		map->txtr->data_h = map->txtr->north_data;
		map->txtr->data_v = map->txtr->east_data;
	}
}

void	get_txtr(t_map *map, double ray_angl, int i)
{
	ray_angl = denormalize_angle(ray_angl);
	if (at_door(map, map->rndr->wall->rays[i].x, map->rndr->wall->rays[i].y, i))
	{
		map->txtr->data_h = map->rndr->doors->door_data;
		map->txtr->data_v = map->rndr->doors->door_data;
	}
	else if (!ray_is_down(ray_angl) && ray_is_right(ray_angl))
	{
			map->txtr->data_h = map->txtr->south_data;
			map->txtr->data_v = map->txtr->west_data;
	}
	else
		get_txtr_assist(map, ray_angl);
}

bool	ray_is_down(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (true);
	return (false);
}

bool	ray_is_right(double angle)
{
	if (angle < (M_PI / 2) || angle > (1.5 * M_PI))
		return (true);
	return (false);
}
