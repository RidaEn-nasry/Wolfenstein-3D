/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:24:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/28 11:57:50 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	project3d(t_map	*map)
{
	int	i;
	int	txtr_x;

	i = 0;
	while (i < WIDTH)
	{
		set_wall_info(map, i);
		project_ceiling(map, i);
		if (map->rndr->wall->vert[i] == true)
			txtr_x = (int)map->rndr->wall->rays[i].y % 64;
		else
			txtr_x = (int)map->rndr->wall->rays[i].x % 64;
		get_txtr(map, map->rndr->wall->arr_angl[i]);
		project_wall(map, i, txtr_x);
		project_floor(map, i);
		i++;
	}
}

t_wall	*cast_v(t_map *map, double ray_angl)
{
	t_vector	inters;
	t_vector	nwall;
	t_wall		*tmp;
	t_vector	start;

	exit_free_if(!(tmp = malloc(sizeof(*tmp))), "Err:\n\tmalloc failed\n", map, 1);
	exit_free_if(!(tmp->wall = malloc(sizeof(*tmp->wall))), \
	"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(tmp->step = malloc(sizeof(*tmp->step))), \
	"Error:\n\tmalloc failed", map, 1);
	start.x = map->rndr->pvec->x + (PLY_SIZE / 2);
	start.y = map->rndr->pvec->y + (PLY_SIZE / 2);
	ray_angl = normalize_ang(ray_angl);
	inters = get_vert_inters(tmp, ray_angl, start);
	nwall.x = inters.x;
	nwall.y = inters.y;
	if (!ray_is_right(ray_angl))
		nwall.x -= 1;
	while (nwall.x >= 0 && nwall.x <= (CELL_SIZE * map->w) && \
	nwall.y >= 0 && nwall.y <= (CELL_SIZE * map->h))
		if (check_inters_v(map, &nwall, tmp, ray_angl))
			break ;
	if (!map->txtr->found_v)
		set_biggest_dist(tmp);
	return (tmp);
}

t_wall	*cast_h(t_map *map, double ray_angl)
{
	t_vector	nwall;
	t_wall		*tmp;
	t_vector	start;
	t_vector	inter;

	exit_free_if(!(tmp = malloc(sizeof(*tmp))), "Error:\n", map, 1);
	exit_free_if(!(tmp->wall = malloc(sizeof(*tmp->wall))), \
	"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(tmp->step = malloc(sizeof(t_wall))), \
	"Error:\nmalloc failed", map, 1);
	start.x = map->rndr->pvec->x + (PLY_SIZE / 2);
	start.y = map->rndr->pvec->y + (PLY_SIZE / 2);
	ray_angl = normalize_ang(ray_angl);
	inter = get_horiz_inters(tmp, ray_angl, start);
	nwall.x = inter.x;
	nwall.y = inter.y;
	if (!ray_is_down(ray_angl))
		nwall.y -= 1;
	while (nwall.x >= 0 && nwall.x <= (CELL_SIZE * map->w) && \
	nwall.y >= 0 && nwall.y <= (CELL_SIZE * map->h))
		if (check_inters_h(map, &nwall, tmp, ray_angl))
			break ;
	if (!map->txtr->found_h)
		set_biggest_dist(tmp);
	return (tmp);
}

void	cast(t_map *map, double ray_angl)
{	
	t_wall		*wall_h;
	t_wall		*wall_v;

	wall_h = cast_h(map, ray_angl);
	wall_v = cast_v(map, ray_angl);
	get_smaller_dist(map, wall_h, wall_v, ray_angl);
	free(wall_h->wall);
	free(wall_h->step);
	free(wall_h);
	free(wall_v->wall);
	free(wall_v->step);
	free(wall_v);
}

void	cast_rays(t_map *map)
{
	double	ray_angl;
	int		i;

	i = 0;
	ray_angl = map->rndr->rot_angl - (map->rndr->fov / 2);
	while (i < WIDTH)
	{
		map->txtr->found_v = false;
		map->txtr->found_h = false;
		cast(map, ray_angl);
		if (map->txtr->found_v)
		{
			map->rndr->wall->vert[i] = true;
			map->rndr->wall->horiz[i] = false;
		}
		else
		{
			map->rndr->wall->vert[i] = false;
			map->rndr->wall->horiz[i] = true;
		}
		ray_angl += (map->rndr->fov / WIDTH);
		i++;
	}
}
