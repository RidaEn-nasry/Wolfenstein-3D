/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 06:12:01 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 16:32:35 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	project_ceiling(t_map *map, int i)
{
	int	y;

	y = 0;
	while (y < map->rndr->proj->top_pix)
	{
		map->mlx->img_data[y * WIDTH + i] = map->clr->ceiling;
		y++;
	}
}

void	project_wall(t_map *map, int i, int txtr_x)
{
	int	txtr_y;
	int	y;
	int	dist_from_top;

	y = map->rndr->proj->top_pix;
	while (y < map->rndr->proj->botom_pix)
	{
		if (map->rndr->wall->vert[i] == true)
			map->txtr->data = map->txtr->data_v;
		else
			map->txtr->data = map->txtr->data_h;
		dist_from_top = y + (map->rndr->wall->wall_height / 2) - (HEIGHT / 2);
		txtr_y = (int)(dist_from_top * ((float)CELL_SIZE / \
		(int)map->rndr->wall->wall_height));
		map->mlx->img_data[(y * WIDTH + i)] = \
		map->txtr->data[(txtr_y * 64 + txtr_x)];
		y++;
	}
}

void	project_floor(t_map *map, int i)
{
	int	y;

	y = map->rndr->proj->botom_pix;
	while (y < HEIGHT)
	{
		map->mlx->img_data[(y * WIDTH + i)] = map->clr->floor;
		y++;
	}
}
