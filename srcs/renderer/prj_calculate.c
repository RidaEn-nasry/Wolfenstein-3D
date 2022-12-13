/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prj_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 05:54:44 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 16:32:30 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	set_wall_info(t_map *map, int i)
{
	map->rndr->proj->proj_plan = ((WIDTH / 2) / \
	tan(map->rndr->fov / 2.00));
	map->rndr->wall->arr_dist[i] *= cos(map->rndr->wall->arr_angl[i] - \
	map->rndr->rot_angl);
	map->rndr->proj->wall_proj_height = (CELL_SIZE / \
	map->rndr->wall->arr_dist[i]) * map->rndr->proj->proj_plan;
	map->rndr->wall->wall_height = (int)map->rndr->proj->wall_proj_height;
	map->rndr->proj->top_pix = (int)(HEIGHT / 2) - \
	(int)(map->rndr->proj->wall_proj_height / 2);
	if (map->rndr->proj->top_pix < 0 || map->rndr->proj->top_pix > HEIGHT)
		map->rndr->proj->top_pix = 0;
	map->rndr->proj->botom_pix = (HEIGHT / 2) + \
	(map->rndr->wall->wall_height / 2);
	if (map->rndr->proj->botom_pix > HEIGHT || map->rndr->proj->botom_pix < 0)
		map->rndr->proj->botom_pix = HEIGHT;
}
