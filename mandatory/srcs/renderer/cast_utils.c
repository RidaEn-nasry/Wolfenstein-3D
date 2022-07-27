/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:46:49 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 06:31:06 by ren-nasr         ###   ########.fr       */
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

void	get_txtr(t_map *map, double ray_angl)
{
	ray_angl = denormalize_angle(ray_angl);
	if (!ray_is_down(ray_angl) && ray_is_right(ray_angl))
	{
			map->txtr->data_h = map->txtr->south_data;
			map->txtr->data_v = map->txtr->west_data;
	}
	if (!ray_is_down(ray_angl) && !ray_is_right(ray_angl))
	{
		map->txtr->data_h = map->txtr->south_data;
		map->txtr->data_v = map->txtr->east_data;
	}
	if (ray_is_down(ray_angl) && ray_is_right(ray_angl))
	{
		map->txtr->data_h = map->txtr->north_data;
		map->txtr->data_v = map->txtr->west_data;
	}
	if (ray_is_down(ray_angl) && !ray_is_right(ray_angl))
	{
		map->txtr->data_h = map->txtr->north_data;
		map->txtr->data_v = map->txtr->east_data;
	}
}

double	get_dist(double x0, double x1, double y0, double y1)
{
	return (sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0))));
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
