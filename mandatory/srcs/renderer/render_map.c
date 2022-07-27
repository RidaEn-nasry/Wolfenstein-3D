/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:11:27 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/25 20:11:20 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

int	red_cross(t_map *map)
{
	mlx_destroy_window(map->mlx->mlx, map->mlx->win);
	free(map->mlx->img);
	free(map->mlx);
	exit(0);
}

void	render_map(t_map *map)
{
	map = init_rndr(map);
	draw_map(map, 0);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
	mlx_hook(map->mlx->win, 2, 1L << 0, &move_player, map);
	mlx_hook(map->mlx->win, 17, 0L, &red_cross, map);
	mlx_loop(map->mlx->mlx);
}
