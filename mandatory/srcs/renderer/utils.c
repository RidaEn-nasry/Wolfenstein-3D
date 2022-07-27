/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:43:53 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/25 19:10:47 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

t_map	*add_dist(t_map *map, double value, double ray_angle)
{
	size_t	i;

	if (map->rndr->wall->len_arr == WIDTH)
		map->rndr->wall->len_arr = 0;
	i = map->rndr->wall->len_arr - 1;
	map->rndr->wall->arr_dist[i] = value;
	map->rndr->wall->arr_angl[i] = ray_angle;
	map->rndr->wall->len_arr += 1;
	return (map);
}

t_map	*add_ray_coor(t_map *map, double x, double y)
{
	if (map->rndr->wall->rys_len >= WIDTH)
		map->rndr->wall->rys_len = 0;
	map->rndr->wall->rays[map->rndr->wall->rys_len].x = x;
	map->rndr->wall->rays[map->rndr->wall->rys_len].y = y;
	map->rndr->wall->rys_len += 1;
	return (map);
}
