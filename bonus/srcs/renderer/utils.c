/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:43:53 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 22:23:16 by mkarim           ###   ########.fr       */
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

int	get_mouse_x(t_map *map)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(map->mlx->win, &x, &y);
	return (x);
}

double	get_turn_spd(int x, int prev_x)
{
	double	turn_spd;
	double	diff;

	diff = abs(x - prev_x);
	turn_spd = degtorad(diff / 100 + 2);
	return (turn_spd);
}

void	update_screen(t_map *map)
{
	mlx_clear_window(map->mlx->mlx, map->mlx->win);
	map = new_img(map);
	draw_map(map, 1);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
}
