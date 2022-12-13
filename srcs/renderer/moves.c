/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:09:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 10:55:14 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	update_pos(double *x, double *y, t_map *map)
{
	int	move_step;

	move_step = map->rndr->walk_dir * map->rndr->walk_spd;
	*x += (cos(map->rndr->rot_angl) * move_step);
	*y += (sin(map->rndr->rot_angl) * move_step);
}

void	update_ang(t_map *map, double *ang)
{
	*ang += (map->rndr->turn_dir * map->rndr->turn_spd);
}

bool	inside_wall(double x, double y, t_map *map)
{
	t_moves	mvs;

	mvs.i = -1;
	mvs.incx = 0;
	mvs.incy = 0;
	while (++mvs.i < 4)
	{
		x = map->rndr->pvec->x + mvs.incx;
		y = map->rndr->pvec->y + mvs.incy;
		update_pos(&x, &y, map);
		mvs.index_x = x / CELL_SIZE;
		mvs.index_y = y / CELL_SIZE;
		if (map->map[mvs.index_y][mvs.index_x] == '1' || \
		map->map[mvs.index_y][mvs.index_x] == '2')
			return (true);
		if (mvs.i == 0)
			mvs.incx += PLY_SIZE;
		else if (mvs.i == 1)
			mvs.incy += PLY_SIZE;
		else if (mvs.i == 2)
			mvs.incx -= PLY_SIZE;
	}
	return (false);
}

void	move_right(t_map *map)
{
	t_moves	moves;

	moves.incx = 0;
	moves.incy = 0;
	moves.i = -1;
	while (++moves.i < 4)
	{
		moves.x = map->rndr->pvec->x + cos(map->rndr->rot_angl
				+ degtorad(90)) * 4;
		moves.y = map->rndr->pvec->y + sin(map->rndr->rot_angl
				+ degtorad(90)) * 4;
		moves.index_x = (moves.x + moves.incx) / 64;
		moves.index_y = (moves.y + moves.incy) / 64;
		if (map->map[moves.index_y][moves.index_x] == '1'
			|| map->map[moves.index_y][moves.index_x] == '2')
			return ;
		if (moves.i == 0)
			moves.incx += 4;
		else if (moves.i == 1)
			moves.incy += 4;
		else if (moves.i == 2)
			moves.incx -= 4;
	}
	map->rndr->pvec->x = moves.x;
	map->rndr->pvec->y = moves.y;
}

void	move_left(t_map *map)
{
	t_moves	moves;

	moves.incx = 0;
	moves.incy = 0;
	moves.i = -1;
	while (++moves.i < 4)
	{
		moves.x = map->rndr->pvec->x + cos(map->rndr->rot_angl
				- degtorad(90)) * 4;
		moves.y = map->rndr->pvec->y + sin(map->rndr->rot_angl
				- degtorad(90)) * 4;
		moves.index_x = (moves.x + moves.incx) / 64;
		moves.index_y = (moves.y + moves.incy) / 64;
		if (map->map[moves.index_y][moves.index_x] == '1'
		|| map->map[moves.index_y][moves.index_x] == '2')
			return ;
		if (moves.i == 0)
			moves.incx += 4;
		else if (moves.i == 1)
			moves.incy += 4;
		else if (moves.i == 2)
			moves.incx -= 4;
	}
	map->rndr->pvec->x = moves.x;
	map->rndr->pvec->y = moves.y;
}
